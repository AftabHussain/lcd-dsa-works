#!/bin/tcsh
(cat -n my_device.c)>&my_device.c.txt
(cat -n device.h)>&device.h.txt
(cat -n device_manager.c)>&device_manager.c.txt

