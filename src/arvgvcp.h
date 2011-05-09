/* Aravis - Digital camera library
 *
 * Copyright © 2009-2010 Emmanuel Pacaud
 *
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; either
 * version 2 of the License, or (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General
 * Public License along with this library; if not, write to the
 * Free Software Foundation, Inc., 59 Temple Place, Suite 330,
 * Boston, MA 02111-1307, USA.
 *
 * Author: Emmanuel Pacaud <emmanuel@gnome.org>
 */

#ifndef ARV_GVCP_H
#define ARV_GVCP_H

#include <arvtypes.h>
#include <arvdebug.h>

G_BEGIN_DECLS

#define ARV_GVCP_PORT	3956

#define ARV_GVBS_VERSION_OFFSET				0x00000000
#define ARV_GVBS_VERSION_MINOR_MASK			0x0000ffff
#define ARV_GVBS_VERSION_MINOR_POS			0
#define ARV_GVBS_VERSION_MAJOR_MASK			0xffff0000
#define ARV_GVBS_VERSION_MAJOR_POS			16

#define ARV_GVBS_DEVICE_MODE_OFFSET			0x00000004
#define ARV_GVBS_DEVICE_MODE_BIG_ENDIAN			1 << 31
#define ARV_GVBS_DEVICE_MODE_CHARACTER_SET_MASK		0x0000ffff
#define ARV_GVBS_DEVICE_MODE_CHARACTER_SET_POS		0

#define ARV_GVBS_DEVICE_MAC_ADDRESS_HIGH_OFFSET		0x00000008
#define ARV_GVBS_DEVICE_MAC_ADDRESS_LOW_OFFSET		0x0000000c

#define ARV_GVBS_SUPPORTED_IP_CONFIGURATION_OFFSET	0x00000010
#define ARV_GVBS_CURRENT_IP_CONFIGURATION_OFFSET	0x00000014
#define ARV_GVBS_IP_CONFIGURATION_PERSISTENT		1 << 0
#define ARV_GVBS_IP_CONFIGURATION_DHCP			1 << 1
#define ARV_GVBS_IP_CONFIGURATION_LLA			1 << 2

#define ARV_GVBS_CURRENT_IP_ADDRESS_OFFSET		0x00000024
#define ARV_GVBS_CURRENT_SUBNET_MASK_OFFSET		0x00000034
#define ARV_GVBS_CURRENT_GATEWAY_OFFSET			0x00000044

#define ARV_GVBS_MANUFACTURER_NAME_OFFSET		0x00000048
#define ARV_GVBS_MANUFACTURER_NAME_SIZE			32

#define ARV_GVBS_MODEL_NAME_OFFSET			0x00000068
#define ARV_GVBS_MODEL_NAME_SIZE			32

#define ARV_GVBS_DEVICE_VERSION_OFFSET			0x00000088
#define ARV_GVBS_DEVICE_VERSION_SIZE			32

#define ARV_GVBS_MANUFACTURER_INFORMATIONS_OFFSET	0x000000a8
#define ARV_GVBS_MANUFACTURER_INFORMATIONS_SIZE		48

#define ARV_GVBS_SERIAL_NUMBER_OFFSET			0x000000d8
#define ARV_GVBS_SERIAL_NUMBER_SIZE			16

#define ARV_GVBS_USER_DEFINED_NAME_OFFSET		0x000000e8
#define ARV_GVBS_USER_DEFINED_NAME_SIZE			16

#define ARV_GVBS_DISCOVERY_DATA_SIZE			0xf8

#define ARV_GVBS_XML_URL_0_OFFSET			0x00000200
#define ARV_GVBS_XML_URL_1_OFFSET			0x00000400
#define ARV_GVBS_XML_URL_SIZE				512

#define ARV_GVBS_N_NETWORK_INTERFACES_OFFSET		0x00000600

#define	ARV_GVBS_PERSISTENT_IP_ADDRESS_0_OFFSET		0x0000064c
#define	ARV_GVBS_PERSISTENT_SUBNET_MASK_0_OFFSET	0x0000065c
#define	ARV_GVBS_PERSISTENT_GATEWAY_0_OFFSET		0x0000066c

#define ARV_GVBS_N_MESSAGE_CHANNELS_OFFSET		0x00000900
#define ARV_GVBS_N_STREAM_CHANNELS_OFFSET		0x00000904

#define ARV_GVBS_GVCP_CAPABILITY_OFFSET			0x00000934
#define ARV_GVBS_GVCP_CAPABILITY_CONCATENATION		1 << 0
#define ARV_GVBS_GVCP_CAPABILITY_WRITE_MEMORY		1 << 1
#define ARV_GVBS_GVCP_CAPABILITY_PACKET_RESEND		1 << 2
#define ARV_GVBS_GVCP_CAPABILITY_EVENT			1 << 3
#define ARV_GVBS_GVCP_CAPABILITY_EVENT_DATA		1 << 4
#define ARV_GVBS_GVCP_CAPABILITY_SERIAL_NUMBER		1 << 30
#define ARV_GVBS_GVCP_CAPABILITY_NAME_REGISTER		1 << 31

#define ARV_GVBS_HEARTBEAT_TIMEOUT_OFFSET		0x00000938
#define ARV_GVBS_TIMESTAMP_TICK_FREQUENCY_HIGH_OFFSET	0x0000093c
#define ARV_GVBS_TIMESTAMP_TICK_FREQUENCY_LOW_OFFSET	0x00000940
#define ARV_GVBS_TIMESTAMP_CONTROL_OFFSET		0x00000944
#define ARV_GVBS_TIMESTAMP_LATCHED_VALUE_HIGH_OFFSET	0x00000948
#define ARV_GVBS_TIMESTAMP_LATCHED_VALUE_LOW_OFFSET	0x0000094c

#define ARV_GVBS_CONTROL_CHANNEL_PRIVILEGE_OFFSET	0x00000a00
#define ARV_GVBS_CONTROL_CHANNEL_PRIVILEGE_CONTROL	1 << 1
#define ARV_GVBS_CONTROL_CHANNEL_PRIVILEGE_EXCLUSIVE	1 << 0

#define ARV_GVBS_STREAM_CHANNEL_0_PORT_OFFSET		0x00000d00

#define ARV_GVBS_STREAM_CHANNEL_0_PACKET_SIZE_OFFSET		0x00000d04
#define ARV_GVBS_STREAM_CHANNEL_0_PACKET_SIZE_MASK		0x0000ffff
#define ARV_GVBS_STREAM_CHANNEL_0_PACKET_SIZE_POS		0
#define ARV_GVBS_STREAM_CHANNEL_0_PACKET_BIG_ENDIAN		1 << 29
#define ARV_GVBS_STREAM_CHANNEL_0_PACKET_DO_NOT_FRAGMENT	1 << 30
#define ARV_GVBS_STREAM_CHANNEL_0_PACKET_SIZE_FIRE_TEST		1 << 31

#define ARV_GVBS_STREAM_CHANNEL_0_PACKET_DELAY_OFFSET		0x00000d08

#define ARV_GVBS_STREAM_CHANNEL_0_IP_ADDRESS_OFFSET		0x00000d18

#define ARV_GVBS_DEVICE_LINK_SPEED_0_OFFSET			0x0000b000

#define ARV_GVBS_STREAM_CHANNEL_0_PACKET_SIZE_MIN_OFFSET		0x0000c000
#define ARV_GVBS_STREAM_CHANNEL_0_PACKET_SIZE_MAX_OFFSET		0x0000c004
#define ARV_GVBS_STREAM_CHANNEL_0_PACKET_DELAY_MIN_OFFSET		0x0000c008
#define ARV_GVBS_STREAM_CHANNEL_0_PACKET_DELAY_MAX_OFFSET		0x0000c00c
#define ARV_GVBS_STREAM_CHANNEL_0_FRAME_TRANSMISSION_DELAY_OFFSET	0x0000c010
#define ARV_GVBS_STREAM_CHANNEL_0_FRAME_TRANSMISSION_DELAY_MIN_OFFSET	0x0000c014
#define ARV_GVBS_STREAM_CHANNEL_0_FRAME_TRANSMISSION_DELAY_MAX_OFFSET	0x0000c018
#define ARV_GVBS_STREAM_CHANNEL_0_BANDWITDH_RESERVE_OFFSET		0x0000c01c
#define ARV_GVBS_STREAM_CHANNEL_0_BANDWITDH_RESERVE_MIN_OFFSET		0x0000c020
#define ARV_GVBS_STREAM_CHANNEL_0_BANDWITDH_RESERVE_MAX_OFFSET		0x0000c024
#define ARV_GVBS_STREAM_CHANNEL_0_BANDWITDH_RESERVE_ACCUMULATION_OFFSET	0x0000c028
#define ARV_GVBS_STREAM_CHANNEL_0_BANDWITDH_RESERVE_ACCUMULATION_MIN_OFFSET	0x0000c02c
#define ARV_GVBS_STREAM_CHANNEL_0_BANDWITDH_RESERVE_ACCUMULATION_MAX_OFFSET	0x0000c030
#define ARV_GVBS_STREAM_CHANNEL_0_THROUGHPUT_MAX_OFFSET			0x0000c100
#define ARV_GVBS_STREAM_CHANNEL_0_CURRENT_THOURGHPUT_OFFSET		0x0000c104
#define ARV_GVBS_STREAM_CHANNEL_0_ASSIGNED_BANDWIDTH_OFFSET		0x0000c108
#define ARV_GVBS_STREAM_CHANNEL_0_FRAME_JITTER_MAX_OFFSET		0x0000c10c

#define ARV_GVCP_DATA_SIZE_MAX				512

typedef enum {
	ARV_GVCP_PACKET_TYPE_ACK =		0x0000,
	ARV_GVCP_PACKET_TYPE_RESEND =		0x4200,
	ARV_GVCP_PACKET_TYPE_CMD = 		0x4201,
	ARV_GVCP_PACKET_TYPE_ERROR =		0x8006
} ArvGvcpPacketType;

typedef enum {
	ARV_GVCP_COMMAND_DISCOVERY_CMD =	0x0002,
	ARV_GVCP_COMMAND_DISCOVERY_ACK =	0x0003,
	ARV_GVCP_COMMAND_BYE_CMD = 		0x0004,
	ARV_GVCP_COMMAND_BYE_ACK = 		0x0005,
	ARV_GVCP_COMMAND_PACKET_RESEND_CMD =	0x0040,
	ARV_GVCP_COMMAND_PACKET_RESEND_ACK =	0x0041,
	ARV_GVCP_COMMAND_READ_REGISTER_CMD =	0x0080,
	ARV_GVCP_COMMAND_READ_REGISTER_ACK =	0x0081,
	ARV_GVCP_COMMAND_WRITE_REGISTER_CMD =	0x0082,
	ARV_GVCP_COMMAND_WRITE_REGISTER_ACK =	0x0083,
	ARV_GVCP_COMMAND_READ_MEMORY_CMD =	0x0084,
	ARV_GVCP_COMMAND_READ_MEMORY_ACK =	0x0085,
	ARV_GVCP_COMMAND_WRITE_MEMORY_CMD =	0x0086,
	ARV_GVCP_COMMAND_WRITE_MEMORY_ACK =	0x0087
} ArvGvcpCommand;

typedef struct {
	guint16 packet_type;
	guint16 command;
	guint16 size;
	guint16 count;
}  __attribute__((__packed__)) ArvGvcpHeader;

typedef struct {
	ArvGvcpHeader header;
	unsigned char data[];
} ArvGvcpPacket;

void 			arv_gvcp_packet_free 			(ArvGvcpPacket *packet);
ArvGvcpPacket * 	arv_gvcp_packet_new_read_memory_cmd 	(guint32 address, guint32 size,
								 guint32 packet_count, size_t *packet_size);
ArvGvcpPacket * 	arv_gvcp_packet_new_read_memory_ack 	(guint32 address, guint32 size, guint32 packet_count,
								 size_t *packet_size);
ArvGvcpPacket * 	arv_gvcp_packet_new_write_memory_cmd	(guint32 address, guint32 size,
								 guint32 packet_count, size_t *packet_size);
ArvGvcpPacket * 	arv_gvcp_packet_new_write_memory_ack	(guint32 address,
								 guint32 packet_count, size_t *packet_size);
ArvGvcpPacket * 	arv_gvcp_packet_new_read_register_cmd 	(guint32 address,
								 guint32 packet_count, size_t *packet_size);
ArvGvcpPacket * 	arv_gvcp_packet_new_read_register_ack 	(guint32 value,
								 guint32 packet_count, size_t *packet_size);
ArvGvcpPacket * 	arv_gvcp_packet_new_write_register_cmd 	(guint32 address, guint32 value,
								 guint32 packet_count, size_t *packet_size);
ArvGvcpPacket * 	arv_gvcp_packet_new_write_register_ack 	(guint32 address,
								 guint32 packet_count, size_t *packet_size);
ArvGvcpPacket * 	arv_gvcp_packet_new_discovery_cmd 	(size_t *size);
ArvGvcpPacket * 	arv_gvcp_packet_new_discovery_ack 	(size_t *packet_size);
ArvGvcpPacket * 	arv_gvcp_packet_new_packet_resend_cmd 	(guint32 frame_id,
								 guint32 first_block, guint32 last_block,
								 guint32 packet_count, size_t *packet_size);
char * 			arv_gvcp_packet_to_string 		(const ArvGvcpPacket *packet);
void 			arv_gvcp_packet_debug 			(const ArvGvcpPacket *packet, ArvDebugLevel level);

static inline ArvGvcpPacketType
arv_gvcp_packet_get_packet_type (ArvGvcpPacket *packet)
{
	if (packet == NULL)
		return ARV_GVCP_PACKET_TYPE_ERROR;

	return g_ntohs (packet->header.packet_type);
}

static inline ArvGvcpCommand
arv_gvcp_packet_get_command (ArvGvcpPacket *packet)
{
	if (packet == NULL)
		return 0;

	return g_ntohs (packet->header.command);
}

static inline void
arv_gvcp_packet_set_packet_count (ArvGvcpPacket *packet, guint16 count)
{
	if (packet != NULL)
		packet->header.count = g_htons (count);
}

static inline guint16
arv_gvcp_packet_get_packet_count (ArvGvcpPacket *packet)
{
	if (packet == NULL)
		return 0;

	return g_ntohs (packet->header.count);
}

static inline void
arv_gvcp_packet_get_read_memory_cmd_infos (const ArvGvcpPacket *packet, guint32 *address, guint32 *size)
{
	if (packet == NULL)
		return;
	if (address != NULL)
		*address = g_ntohl (*((guint32 *) ((char *) packet + sizeof (ArvGvcpPacket))));
	if (size != NULL)
		*size = (g_ntohl (*((guint32 *) ((char *) packet + sizeof (ArvGvcpPacket) + sizeof (guint32))))) &
			0xffff;
}

static inline size_t
arv_gvcp_packet_get_read_memory_ack_size (guint32 data_size)
{
	return sizeof (ArvGvcpHeader) + sizeof (guint32) + data_size;
}

static inline void *
arv_gvcp_packet_get_read_memory_ack_data (const ArvGvcpPacket *packet)
{
	return (char *) packet + sizeof (ArvGvcpHeader) + sizeof (guint32);
}

static inline void
arv_gvcp_packet_get_write_memory_cmd_infos (const ArvGvcpPacket *packet, guint32 *address, guint32 *size)
{
	if (packet == NULL)
		return;

	if (address != NULL)
		*address = g_ntohl (*((guint32 *) ((char *) packet + sizeof (ArvGvcpPacket))));
	if (size != NULL)
		*size = g_ntohs (packet->header.size) - sizeof (guint32);
}

static inline void *
arv_gvcp_packet_get_write_memory_cmd_data (const ArvGvcpPacket *packet)
{
	return (char *) packet + sizeof (ArvGvcpPacket) + sizeof (guint32);
}

static inline size_t
arv_gvcp_packet_get_write_memory_ack_size (void)
{
	return sizeof (ArvGvcpPacket) + sizeof (guint32);
}

static inline void
arv_gvcp_packet_get_read_register_cmd_infos (const ArvGvcpPacket *packet, guint32 *address)
{
	if (packet == NULL)
		return;
	if (address != NULL)
		*address = g_ntohl (*((guint32 *) ((char *) packet + sizeof (ArvGvcpPacket))));
}

static inline guint32
arv_gvcp_packet_get_read_register_ack_value (const ArvGvcpPacket *packet)
{
	if (packet == NULL)
		return 0;
	return g_ntohl (*((guint32 *) ((char *) packet + sizeof (ArvGvcpPacket))));
}

static inline void
arv_gvcp_packet_get_write_register_cmd_infos (const ArvGvcpPacket *packet, guint32 *address, guint32 *value)
{
	if (packet == NULL)
		return;
	if (address != NULL)
		*address = g_ntohl (*((guint32 *) ((char *) packet + sizeof (ArvGvcpPacket))));
	if (value != NULL)
		*value = g_ntohl (*((guint32 *) ((char *) packet + sizeof (ArvGvcpPacket) + sizeof (guint32))));
}

G_END_DECLS

#endif
