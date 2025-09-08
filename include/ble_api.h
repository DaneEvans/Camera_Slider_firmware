/**
 * @file ble_api.h
 * @brief BLE API Documentation for Camera Slider Firmware
 * @author Dane Evans
 * @version 1.0
 * @date 2024
 *
 * @details This file documents the Bluetooth Low Energy (BLE) API interface
 * that allows communication between the camera slider device and a phone/computer.
 * The API is implemented using the Adafruit Bluefruit LE UART service.
 *
 * @note This is a documentation-only header file. The actual implementation
 * is in src/bleuart.ino
 */

#ifndef BLE_API_H
#define BLE_API_H

#ifdef __cplusplus
extern "C" {
#endif

/**
 * @defgroup ble_api API Documentation
 * @{
 *
 * @brief Complete API reference for BLE communication with the Camera Slider
 *
 * The Camera Slider firmware provides a BLE UART interface that allows
 * remote control and monitoring of the device. This API supports both
 * command-based control and real-time status updates.
 */



/**
 * @defgroup ble_commands Commands
 * @{
 *
 * @brief Available commands that can be sent via BLE UART
 *
 * Commands are sent as single characters or strings over the BLE UART service.
 * All commands are processed in the main loop and provide immediate feedback.
 */

/**
 * @brief Move slider forward or backwards
 *
 * @details
 * - Command: 'x <int>'
 * - Action: Moves the camera slider forward or backwards (-) by int steps.
 * - Response: "moving x steps" sent to serial
 *
 * @see slide_dist()
 * @see SLIDE_SPEED
 */
#define SLIDE_Movement 'x <int>'

/**
 * @brief Move slider to an absolute position.  
 *
 * @details
 * - Command: 'X <int>'
 * - Action: Moves the camera slider to a given position.
 * - Follows the set speed.
 * - Response: "Moving to X" sent to serial
 *
 * @note This command changes the current direction and moves the slider
 * @see slide_dist()
 * @see SLIDE_SPEED
 */
#define SLIDE_Abs_Movement 'X <int>'

/**
 * @brief Set movement speed
 *
 * @details
 * - Command: "speed:<value>"
 * - Action: Sets the movement speed (1-100)
 * - Response: "Speed set to <value>"
 *
 * @note This command is planned for future implementation
 */
#define SLIDE_SPEED "S:"

/**
 * @brief Move rotator cw or ccw 
 *
 * @details
 * - Command: 'r <int>'
 * - Action: Moves the camera slider cw or ccw (-) by int steps.
 * - Response: "rotating r steps" sent to serial
 *
 */
#define ROTATE_Movement 'r <int>'

/**
 * @brief Move rotator to an absolute position.  
 *
 * @details
 * - Command: 'R <int>'
 * - Action: Moves the camera slider to a given position.
 * - Follows the set speed.
 * - Response: "Rotating to R" sent to serial
 *
 */
#define ROTATE_Abs_Movement 'R <int>'

/**
 * @brief Set rotationmovement speed
 *
 * @details
 * - Command: "Rs:<value>"
 * - Action: Sets the movement speed (1-100)
 * - Response: "Speed set to <value>"
 *
 * @note This command is planned for future implementation
 */
#define ROTATE_SPEED "Rs:"


/**
 * @brief Get device status
 *
 * @details
 * - Command: 's'
 * - Action: Returns current device status and position
 * - Response: JSON formatted status string
 *
 * @note This command is planned for future implementation
 */
#define STATUS 'status:'

/**
 * @brief Emergency stop
 *
 * @details
 * - Command: 'x'
 * - Action: Immediately stops all motor movement
 * - Response: "STOP" confirmation
 *
 * @note This command is planned for future implementation
 */
#define STOP 'K'





/** @} */  // end of ble_commands


/**
 * @defgroup ble_usage Usage Examples
 * @{
 *
 * @brief Common usage patterns and examples
 */

/**
 * @example basic_control.ino
 * @brief Basic BLE control example
 *
 * This example shows how to connect to the Camera Slider and send
 * basic movement commands:
 *
 * @code
 * // Connect to "Camera Slider" device
 * // Send 'a' to move forward
 * // Send 'b' to move backward
 * // Monitor responses for feedback
 * @endcode
 */

/**
 * @example status_monitoring.ino
 * @brief Status monitoring example
 *
 * This example shows how to continuously monitor device status:
 *
 * @code
 * // Connect to device
 * // Send 's' command periodically
 * // Parse JSON status responses
 * // Update UI with current position/speed
 * @endcode
 */

/** @} */  // end of ble_usage

/**
 * @defgroup ble_implementation Implementation Details
 * @{
 *
 * @brief Technical implementation information
 */

/**
 * @brief Main BLE processing loop
 *
 * @details The main loop processes incoming BLE commands and forwards
 * serial data to connected devices. Command processing includes:
 * - Character-based commands (a, b)
 * - LED state management
 * - Motor control via slide_dist()
 * - Bidirectional data forwarding
 *
 * @see loop() in bleuart.ino
 */
#define BLE_MAIN_LOOP "Main BLE processing loop"

/**
 * @brief Buffer management
 *
 * @details
 * - Input buffer: 64 bytes
 * - Processing delay: 2ms for buffer filling
 * - Character-by-character command processing
 * - Real-time response generation
 */
#define BLE_BUFFER_SIZE 64
#define BLE_PROCESSING_DELAY 2

/**
 * @brief Motor control integration
 *
 * @details BLE commands directly interface with the motor control system:
 * - slide_dist() function calls
 * - Direction changes
 * - Position tracking
 * - Speed control
 *
 * @see motors.h for motor control functions
 */
#define BLE_MOTOR_INTEGRATION "Direct motor control integration"

/** @} */  // end of ble_implementation


/** @} */  // end of ble_api

#ifdef __cplusplus
}
#endif

#endif  // BLE_API_H
