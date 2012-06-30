/* dual-relay
 * Copyright (C) 2011 Olaf Lüke <olaf@tinkerforge.com>
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

#ifndef DUAL_RELAIS_H
#define DUAL_RELAIS_H

#include <stdint.h>

#define TYPE_SET 1
#define TYPE_GET 2
#define TYPE_SET_MONOFLOP 3
#define TYPE_GET_MONOFLOP 4
#define TYPE_MONOFLOP_DONE 5

typedef struct {
	uint8_t stack_id;
	uint8_t type;
	uint16_t length;
} __attribute__((__packed__)) StandardMessage;

typedef struct {
	uint8_t stack_id;
	uint8_t type;
	uint16_t length;
	bool relay1;
	bool relay2;
} __attribute__((__packed__)) Set;

typedef struct {
	uint8_t stack_id;
	uint8_t type;
	uint16_t length;
} __attribute__((__packed__)) Get;

typedef struct {
	uint8_t stack_id;
	uint8_t type;
	uint16_t length;
	bool relay1;
	bool relay2;
} __attribute__((__packed__)) GetReturn;

typedef struct {
	uint8_t stack_id;
	uint8_t type;
	uint16_t length;
	uint8_t relay;
	bool state;
	uint32_t time;
} __attribute__((__packed__)) SetMonoflop;

typedef struct {
	uint8_t stack_id;
	uint8_t type;
	uint16_t length;
	uint8_t relay;
} __attribute__((__packed__)) GetMonoflop;

typedef struct {
	uint8_t stack_id;
	uint8_t type;
	uint16_t length;
	bool state;
	uint32_t time;
	uint32_t time_remaining;
} __attribute__((__packed__)) GetMonoflopReturn;

typedef struct {
	uint8_t stack_id;
	uint8_t type;
	uint16_t length;
	uint8_t relay;
	bool state;
} __attribute__((__packed__)) MonoflopDone;

void set(uint8_t com, Set *data);
void get(uint8_t com, Get *data);
void set_monoflop(uint8_t com, SetMonoflop *data);
void get_monoflop(uint8_t com, GetMonoflop *data);

void invocation(uint8_t com, uint8_t *data);
void constructor(void);
void destructor(void);
void tick(uint8_t tick_type);

#endif
