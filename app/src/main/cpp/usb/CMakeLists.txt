#
# Copyright 2020 Tyler Qiu.
# YUV420 to RGBA open source project.
#
# Licensed under the Apache License, Version 2.0 (the "License");
# you may not use this file except in compliance with the License.
# You may obtain a copy of the License at
#
#       http://www.apache.org/licenses/LICENSE-2.0
#
# Unless required by applicable law or agreed to in writing, software
# distributed under the License is distributed on an "AS IS" BASIS,
# WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
# See the License for the specific language governing permissions and
# limitations under the License.
#

cmake_minimum_required(VERSION 3.4.1)
project("usb")

include_directories(${CMAKE_SOURCE_DIR}/include)

find_library(log-lib log)

include_directories(./ ./libusb ./android)

add_library(
        usb
        SHARED
        libusb/core.c
        libusb/descriptor.c
        libusb/hotplug.c
        libusb/io.c
        libusb/sync.c
        libusb/strerror.c
        libusb/os/linux_usbfs.c
        libusb/os/events_posix.c
        libusb/os/threads_posix.c
        libusb/os/linux_netlink.c
)

target_link_libraries(usb ${log-lib})
