#pragma once
// MESSAGE TRAJECTORY_NOMINAL PACKING

#define MAVLINK_MSG_ID_TRAJECTORY_NOMINAL 229


typedef struct __mavlink_trajectory_nominal_t {
 uint64_t timestamp; /*< [us] Timestamp (since system boot).*/
 float f_out[20]; /*<  Flat outputs up to 4th derivative.*/
} mavlink_trajectory_nominal_t;

#define MAVLINK_MSG_ID_TRAJECTORY_NOMINAL_LEN 88
#define MAVLINK_MSG_ID_TRAJECTORY_NOMINAL_MIN_LEN 88
#define MAVLINK_MSG_ID_229_LEN 88
#define MAVLINK_MSG_ID_229_MIN_LEN 88

#define MAVLINK_MSG_ID_TRAJECTORY_NOMINAL_CRC 96
#define MAVLINK_MSG_ID_229_CRC 96

#define MAVLINK_MSG_TRAJECTORY_NOMINAL_FIELD_F_OUT_LEN 20

#if MAVLINK_COMMAND_24BIT
#define MAVLINK_MESSAGE_INFO_TRAJECTORY_NOMINAL { \
    229, \
    "TRAJECTORY_NOMINAL", \
    2, \
    {  { "timestamp", NULL, MAVLINK_TYPE_UINT64_T, 0, 0, offsetof(mavlink_trajectory_nominal_t, timestamp) }, \
         { "f_out", NULL, MAVLINK_TYPE_FLOAT, 20, 8, offsetof(mavlink_trajectory_nominal_t, f_out) }, \
         } \
}
#else
#define MAVLINK_MESSAGE_INFO_TRAJECTORY_NOMINAL { \
    "TRAJECTORY_NOMINAL", \
    2, \
    {  { "timestamp", NULL, MAVLINK_TYPE_UINT64_T, 0, 0, offsetof(mavlink_trajectory_nominal_t, timestamp) }, \
         { "f_out", NULL, MAVLINK_TYPE_FLOAT, 20, 8, offsetof(mavlink_trajectory_nominal_t, f_out) }, \
         } \
}
#endif

/**
 * @brief Pack a trajectory_nominal message
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 *
 * @param timestamp [us] Timestamp (since system boot).
 * @param f_out  Flat outputs up to 4th derivative.
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_trajectory_nominal_pack(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg,
                               uint64_t timestamp, const float *f_out)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_TRAJECTORY_NOMINAL_LEN];
    _mav_put_uint64_t(buf, 0, timestamp);
    _mav_put_float_array(buf, 8, f_out, 20);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_TRAJECTORY_NOMINAL_LEN);
#else
    mavlink_trajectory_nominal_t packet;
    packet.timestamp = timestamp;
    mav_array_memcpy(packet.f_out, f_out, sizeof(float)*20);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_TRAJECTORY_NOMINAL_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_TRAJECTORY_NOMINAL;
    return mavlink_finalize_message(msg, system_id, component_id, MAVLINK_MSG_ID_TRAJECTORY_NOMINAL_MIN_LEN, MAVLINK_MSG_ID_TRAJECTORY_NOMINAL_LEN, MAVLINK_MSG_ID_TRAJECTORY_NOMINAL_CRC);
}

/**
 * @brief Pack a trajectory_nominal message on a channel
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param timestamp [us] Timestamp (since system boot).
 * @param f_out  Flat outputs up to 4th derivative.
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_trajectory_nominal_pack_chan(uint8_t system_id, uint8_t component_id, uint8_t chan,
                               mavlink_message_t* msg,
                                   uint64_t timestamp,const float *f_out)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_TRAJECTORY_NOMINAL_LEN];
    _mav_put_uint64_t(buf, 0, timestamp);
    _mav_put_float_array(buf, 8, f_out, 20);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_TRAJECTORY_NOMINAL_LEN);
#else
    mavlink_trajectory_nominal_t packet;
    packet.timestamp = timestamp;
    mav_array_memcpy(packet.f_out, f_out, sizeof(float)*20);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_TRAJECTORY_NOMINAL_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_TRAJECTORY_NOMINAL;
    return mavlink_finalize_message_chan(msg, system_id, component_id, chan, MAVLINK_MSG_ID_TRAJECTORY_NOMINAL_MIN_LEN, MAVLINK_MSG_ID_TRAJECTORY_NOMINAL_LEN, MAVLINK_MSG_ID_TRAJECTORY_NOMINAL_CRC);
}

/**
 * @brief Encode a trajectory_nominal struct
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 * @param trajectory_nominal C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_trajectory_nominal_encode(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg, const mavlink_trajectory_nominal_t* trajectory_nominal)
{
    return mavlink_msg_trajectory_nominal_pack(system_id, component_id, msg, trajectory_nominal->timestamp, trajectory_nominal->f_out);
}

/**
 * @brief Encode a trajectory_nominal struct on a channel
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param trajectory_nominal C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_trajectory_nominal_encode_chan(uint8_t system_id, uint8_t component_id, uint8_t chan, mavlink_message_t* msg, const mavlink_trajectory_nominal_t* trajectory_nominal)
{
    return mavlink_msg_trajectory_nominal_pack_chan(system_id, component_id, chan, msg, trajectory_nominal->timestamp, trajectory_nominal->f_out);
}

/**
 * @brief Send a trajectory_nominal message
 * @param chan MAVLink channel to send the message
 *
 * @param timestamp [us] Timestamp (since system boot).
 * @param f_out  Flat outputs up to 4th derivative.
 */
#ifdef MAVLINK_USE_CONVENIENCE_FUNCTIONS

static inline void mavlink_msg_trajectory_nominal_send(mavlink_channel_t chan, uint64_t timestamp, const float *f_out)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_TRAJECTORY_NOMINAL_LEN];
    _mav_put_uint64_t(buf, 0, timestamp);
    _mav_put_float_array(buf, 8, f_out, 20);
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_TRAJECTORY_NOMINAL, buf, MAVLINK_MSG_ID_TRAJECTORY_NOMINAL_MIN_LEN, MAVLINK_MSG_ID_TRAJECTORY_NOMINAL_LEN, MAVLINK_MSG_ID_TRAJECTORY_NOMINAL_CRC);
#else
    mavlink_trajectory_nominal_t packet;
    packet.timestamp = timestamp;
    mav_array_memcpy(packet.f_out, f_out, sizeof(float)*20);
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_TRAJECTORY_NOMINAL, (const char *)&packet, MAVLINK_MSG_ID_TRAJECTORY_NOMINAL_MIN_LEN, MAVLINK_MSG_ID_TRAJECTORY_NOMINAL_LEN, MAVLINK_MSG_ID_TRAJECTORY_NOMINAL_CRC);
#endif
}

/**
 * @brief Send a trajectory_nominal message
 * @param chan MAVLink channel to send the message
 * @param struct The MAVLink struct to serialize
 */
static inline void mavlink_msg_trajectory_nominal_send_struct(mavlink_channel_t chan, const mavlink_trajectory_nominal_t* trajectory_nominal)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    mavlink_msg_trajectory_nominal_send(chan, trajectory_nominal->timestamp, trajectory_nominal->f_out);
#else
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_TRAJECTORY_NOMINAL, (const char *)trajectory_nominal, MAVLINK_MSG_ID_TRAJECTORY_NOMINAL_MIN_LEN, MAVLINK_MSG_ID_TRAJECTORY_NOMINAL_LEN, MAVLINK_MSG_ID_TRAJECTORY_NOMINAL_CRC);
#endif
}

#if MAVLINK_MSG_ID_TRAJECTORY_NOMINAL_LEN <= MAVLINK_MAX_PAYLOAD_LEN
/*
  This varient of _send() can be used to save stack space by re-using
  memory from the receive buffer.  The caller provides a
  mavlink_message_t which is the size of a full mavlink message. This
  is usually the receive buffer for the channel, and allows a reply to an
  incoming message with minimum stack space usage.
 */
static inline void mavlink_msg_trajectory_nominal_send_buf(mavlink_message_t *msgbuf, mavlink_channel_t chan,  uint64_t timestamp, const float *f_out)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char *buf = (char *)msgbuf;
    _mav_put_uint64_t(buf, 0, timestamp);
    _mav_put_float_array(buf, 8, f_out, 20);
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_TRAJECTORY_NOMINAL, buf, MAVLINK_MSG_ID_TRAJECTORY_NOMINAL_MIN_LEN, MAVLINK_MSG_ID_TRAJECTORY_NOMINAL_LEN, MAVLINK_MSG_ID_TRAJECTORY_NOMINAL_CRC);
#else
    mavlink_trajectory_nominal_t *packet = (mavlink_trajectory_nominal_t *)msgbuf;
    packet->timestamp = timestamp;
    mav_array_memcpy(packet->f_out, f_out, sizeof(float)*20);
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_TRAJECTORY_NOMINAL, (const char *)packet, MAVLINK_MSG_ID_TRAJECTORY_NOMINAL_MIN_LEN, MAVLINK_MSG_ID_TRAJECTORY_NOMINAL_LEN, MAVLINK_MSG_ID_TRAJECTORY_NOMINAL_CRC);
#endif
}
#endif

#endif

// MESSAGE TRAJECTORY_NOMINAL UNPACKING


/**
 * @brief Get field timestamp from trajectory_nominal message
 *
 * @return [us] Timestamp (since system boot).
 */
static inline uint64_t mavlink_msg_trajectory_nominal_get_timestamp(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint64_t(msg,  0);
}

/**
 * @brief Get field f_out from trajectory_nominal message
 *
 * @return  Flat outputs up to 4th derivative.
 */
static inline uint16_t mavlink_msg_trajectory_nominal_get_f_out(const mavlink_message_t* msg, float *f_out)
{
    return _MAV_RETURN_float_array(msg, f_out, 20,  8);
}

/**
 * @brief Decode a trajectory_nominal message into a struct
 *
 * @param msg The message to decode
 * @param trajectory_nominal C-struct to decode the message contents into
 */
static inline void mavlink_msg_trajectory_nominal_decode(const mavlink_message_t* msg, mavlink_trajectory_nominal_t* trajectory_nominal)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    trajectory_nominal->timestamp = mavlink_msg_trajectory_nominal_get_timestamp(msg);
    mavlink_msg_trajectory_nominal_get_f_out(msg, trajectory_nominal->f_out);
#else
        uint8_t len = msg->len < MAVLINK_MSG_ID_TRAJECTORY_NOMINAL_LEN? msg->len : MAVLINK_MSG_ID_TRAJECTORY_NOMINAL_LEN;
        memset(trajectory_nominal, 0, MAVLINK_MSG_ID_TRAJECTORY_NOMINAL_LEN);
    memcpy(trajectory_nominal, _MAV_PAYLOAD(msg), len);
#endif
}
