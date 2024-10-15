#include <linux/module.h>
#include <linux/fs.h>
#include <linux/uaccess.h>
#include <linux/tty.h>
#include <linux/slab.h>

#define SERIAL_DEVICE "/dev/ttyACM0"  // Path to the Arduino device file (changes based on your system)

static struct file *serial_file = NULL;

//It initiates a serial connection to the serial device ttyACM0
static int serial_open(void) {

    // Open the serial port
    serial_file = filp_open(SERIAL_DEVICE, O_RDWR | O_NOCTTY, 0);

    if (IS_ERR(serial_file)) {
        printk(KERN_ALERT "Failed to open the serial device\n");
        return PTR_ERR(serial_file);
    }
    return 0;
}

//It closes the serial connection at the end.
static void serial_close(void) {
    if (serial_file) {
        filp_close(serial_file, NULL);
    }
}

//serial_write is used to send a data to the serial interface port device, which was initiated.  
static ssize_t serial_write(const char *data, size_t size) {
    
    ssize_t ret;

    if (!serial_file) {
        printk(KERN_ALERT "Serial device not opened\n");
        return -EIO;
    }

    // Write the command to the serial device
    ret = vfs_write(serial_file, data, size, &serial_file->f_pos);

    return ret;
}

//simple function which calls serial write whenever the device file has a change.
static ssize_t blink_led(const char *buffer, size_t len) {
    char command = buffer[0];
    
    if (command == '1') {
        serial_write("1", 1);  // Send '1' to Arduino (LED ON)
    } else if (command == '0') {
        serial_write("0", 1);  // Send '0' to Arduino (LED OFF)
    }

    return len;
}

//Below two are initialization and exit functions called.
static int __init led_driver_init(void) {
    printk(KERN_INFO "LED Driver Initialized\n");

    if (serial_open()) {
        printk(KERN_ALERT "Failed to open serial device\n");
        return -1;
    }

    return 0;
}

static void __exit led_driver_exit(void) {
    serial_close();
    printk(KERN_INFO "LED Driver Exited\n");
}

module_init(led_driver_init);
module_exit(led_driver_exit);

MODULE_LICENSE("GPL");
MODULE_AUTHOR("Susil Ramarao");
MODULE_DESCRIPTION("A simple Linux driver to control an Arduino LED via USB");
