/* dual-relay
 * Copyright (C) 2011-2013 Olaf Lüke <olaf@tinkerforge.com>
 *
 * dual-relay.h: Implementation of Dual Relay Bricklet messages
 *
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; either
 * version 2 of the License, or (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU
 * Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public
 * License along with this library; if not, write to the
 * Free Software Foundation, Inc., 59 Temple Place - Suite 330,
 * Boston, MA 02111-1307, USA.
 */

#ifndef DUAL_RELAY_H
#define DUAL_RELAY_H

#include <stdint.h>
#include "bricklib/com/com_common.h"

#define FID_SET 1
#define FID_GET 2
#define FID_SET_MONOFLOP 3
#define FID_GET_MONOFLOP 4
#define FID_MONOFLOP_DONE 5
#define FID_SET_SELECTED_STATE 6

typedef struct {
	MessageHeader header;
} __attribute__((__packed__)) StandardMessage;

typedef struct {
	MessageHeader header;
	bool relay1;
	bool relay2;
} __attribute__((__packed__)) Set;

typedef struct {
	MessageHeader header;
} __attribute__((__packed__)) Get;

typedef struct {
	MessageHeader header;
	bool relay1;
	bool relay2;
} __attribute__((__packed__)) GetReturn;

typedef struct {
	MessageHeader header;
	uint8_t relay;
	bool state;
	uint32_t time;
} __attribute__((__packed__)) SetMonoflop;

typedef struct {
	MessageHeader header;
	uint8_t relay;
} __attribute__((__packed__)) GetMonoflop;

typedef struct {
	MessageHeader header;
	bool state;
	uint32_t time;
	uint32_t time_remaining;
} __attribute__((__packed__)) GetMonoflopReturn;

typedef struct {
	MessageHeader header;
	uint8_t relay;
	bool state;
} __attribute__((__packed__)) MonoflopDone;

typedef struct {
	MessageHeader header;
	uint8_t relay;
	bool state;
} __attribute__((__packed__)) SetSelectedState;

void set(const ComType com, const Set *data);
void get(const ComType com, const Get *data);
void set_monoflop(const ComType com, const SetMonoflop *data);
void get_monoflop(const ComType com, const GetMonoflop *data);
void set_selected_state(const ComType com, const SetSelectedState *data);

void invocation(const ComType com, const uint8_t *data);
void constructor(void);
void destructor(void);
void tick(const uint8_t tick_type);

#endif
