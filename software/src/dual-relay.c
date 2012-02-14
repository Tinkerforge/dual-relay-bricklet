/* dual-relay
 * Copyright (C) 2011 Olaf Lüke <olaf@tinkerforge.com>
 *
 * dual-relay.c: Implementation of Dual Relay Bricklet messages
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

#include "dual-relay.h"

#include "brickletlib/bricklet_entry.h"
#include "bricklib/bricklet/bricklet_communication.h"
#include "bricklib/drivers/adc/adc.h"
#include "config.h"
#include "bricklib/utility/util_definitions.h"

void invocation(uint8_t com, uint8_t *data) {
	switch(((StandardMessage*)data)->type) {
		case TYPE_SET:
			set(com, (Set*)data);
			return;
		case TYPE_GET:
			get(com, (Get*)data);
			return;
	}
}

void set(uint8_t com, Set *data) {
	if(data->relay1) {
		PIN_RELAIS_1.pio->PIO_SODR = PIN_RELAIS_1.mask;
	} else {
		PIN_RELAIS_1.pio->PIO_CODR = PIN_RELAIS_1.mask;
	}

	if(data->relay2) {
		PIN_RELAIS_2.pio->PIO_SODR = PIN_RELAIS_2.mask;
	} else {
		PIN_RELAIS_2.pio->PIO_CODR = PIN_RELAIS_2.mask;
	}
}

void get(uint8_t com, Get *data) {
	GetReturn gr = {
		data->stack_id,
		data->type,
		sizeof(GetReturn),
		PIN_RELAIS_1.pio->PIO_ODSR & PIN_RELAIS_1.mask,
		PIN_RELAIS_2.pio->PIO_ODSR & PIN_RELAIS_2.mask,
	};

	BA->send_blocking_with_timeout(&gr,
	                               sizeof(GetReturn),
	                               com);
}

void constructor(void) {
    PIN_RELAIS_1.type = PIO_OUTPUT_0;
    PIN_RELAIS_1.attribute = PIO_DEFAULT;
    BA->PIO_Configure(&PIN_RELAIS_1, 1);

    PIN_RELAIS_2.type = PIO_OUTPUT_0;
    PIN_RELAIS_2.attribute = PIO_DEFAULT;
    BA->PIO_Configure(&PIN_RELAIS_2, 1);
}

void destructor(void) {
    PIN_RELAIS_1.type = PIO_INPUT;
    PIN_RELAIS_1.attribute = PIO_PULLUP;
    BA->PIO_Configure(&PIN_RELAIS_1, 1);

    PIN_RELAIS_2.type = PIO_INPUT;
    PIN_RELAIS_2.attribute = PIO_PULLUP;
    BA->PIO_Configure(&PIN_RELAIS_2, 1);
}

void tick(uint8_t tick_type) {
	// Nothing has to be done periodically
}

