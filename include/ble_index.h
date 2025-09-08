/**
 * @file ble_index.h
 * @brief BLE API Documentation Index - Main Entry Point
 * @author Camera Slider Team
 * @version 1.0
 * @date 2024
 *
 * @mainpage Overview
 *
 * @section intro_sec Introduction
 *
 * Welcome to the Bluetooth Low Energy (BLE) API documentation for the Camera Slider firmware.
 * This documentation provides everything you need to communicate with and control the Camera Slider
 * device from external applications, mobile apps, or web interfaces.
 *
 * The Camera Slider is a motorized camera slider that can be controlled remotely via BLE,
 * allowing for precise positioning and movement control for photography and videography
 * applications.
 *
 * @section quick_start_sec Quick Start
 *
 * ### 1. Connect to Device
 * - Scan for BLE device named "Camera Slider"
 * - Connect using the UART service UUID: `6E400001-B5A3-F393-E0A9-E50E24DCCA9E`
 * - Use TX characteristic: `6E400002-B5A3-F393-E0A9-E50E24DCCA9E`
 * - Use RX characteristic: `6E400003-B5A3-F393-E0A9-E50E24DCCA9E`
 * - Uses BLE UART
 *
 * ### 2. Send Commands
 * ```python
 * # Move forward
 * await client.write_gatt_char(tx_char, b'a')
 *
 * # Move backward
 * await client.write_gatt_char(tx_char, b'b')
 * ```
 *
 * ### 3. Monitor Responses
 * Subscribe to RX characteristic notifications to receive device feedback and status updates.
 *
 * @section api_overview_sec API Overview
 *
 * The BLE API provides several key areas of functionality:
 *
 * @subsection commands_sec Commands
 * - **Movement Control**: Forward/backward movement with configurable distance
 * - **Status Queries**: Device state, position, and configuration information
 * - **Configuration**: Speed, acceleration, and movement parameters
 * - **System Control**: Emergency stop, reset, and diagnostic functions
 * - [***API Documentation***](group__ble__api.html)
 *
 * 
 *
 * @section resources_sec Additional Resources
 *
 * ### Documentation Files
 * - **`ble_api.h`**: Complete API reference
 * - **`ble_examples.h`**: Usage examples
 * - **`bleuart.ino`**: Firmware implementation
 * - **`motors.h`**: Motor control interface
 *
 * ### External Resources
 * - [Bluetooth SIG](https://www.bluetooth.com/specifications/)
 * - [Nordic Semiconductor](https://www.nordicsemi.com/)
 * - [Adafruit Bluefruit](https://learn.adafruit.com/adafruit-bluefruit-le-uart-friend)
 * - [Web Bluetooth API](https://web.dev/bluetooth/)
 *
 * ### Support
 * - Check the troubleshooting section above
 * - Review error codes and messages
 * - Test with provided examples
 * - Verify firmware version compatibility
 *
 * @section changelog_sec Changelog
 *
 * ### Version 1.0 (Current)
 * - Initial BLE API implementation
 * - Basic movement control (forward/backward)
 * - UART service communication
 * - Device discovery and connection
 * - LED status indication
 *
 * ### Version 1.1 (Planned)
 * - Position tracking and absolute positioning
 * - Speed and acceleration control
 * - Status reporting and monitoring
 * - Enhanced error handling
 *
 * ### Version 1.2 (Planned)
 * - Programmed movement sequences
 * - Configuration management
 * - Data logging capabilities
 * - Multi-device support
 *
 * @section license_sec License
 *
 * This firmware and API documentation are provided under the MIT License.
 * See the LICENSE file for complete terms and conditions.
 *
 * @section contact_sec Contact
 *
 * For questions, bug reports, or feature requests:
 * - **GitHub Issues**: [Camera Slider Firmware Repository](https://github.com/your-repo)
 * - **Email**: your-email@example.com
 * - **Documentation**: This file and generated Doxygen pages
 *
 * ---
 *
 * *This documentation is automatically generated and maintained using Doxygen.
 * For the most up-to-date information, always refer to the generated HTML documentation.*
 */

#ifndef BLE_INDEX_H
#define BLE_INDEX_H

#ifdef __cplusplus
extern "C" {
#endif

/**
 * @defgroup ble_index BLE API Documentation Index
 * @{
 *
 * @brief Main entry point and overview for BLE API documentation
 *
 * This file serves as the central hub for all BLE API documentation,
 * providing navigation, examples, and comprehensive information for
 * developers integrating with the Camera Slider firmware.
 */

/**
 * @brief Documentation version
 *
 * Current version of the BLE API documentation
 */
#define BLE_API_VERSION "1.0"

/**
 * @brief Documentation date
 *
 * Last update date for the BLE API documentation
 */
#define BLE_API_DATE "2024"

/**
 * @brief Main documentation entry point
 *
 * This macro serves as the main entry point for Doxygen documentation
 * and should be referenced in the main page documentation.
 */
#define BLE_API_MAIN_PAGE "BLE API Documentation Index"

/** @} */  // end of ble_index

#ifdef __cplusplus
}
#endif

#endif  // BLE_INDEX_H
