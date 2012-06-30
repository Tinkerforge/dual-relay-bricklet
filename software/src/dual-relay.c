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
		case TYPE_SET_MONOFLOP:
			set_monoflop(com, (SetMonoflop*)data);
			return;
		case TYPE_GET_MONOFLOP:
			get_monoflop(com, (GetMonoflop*)data);
			return;
	}
}

void set(uint8_t com, Set *data) {
	if(data->relay1) {
		PIN_RELAY_1.pio->PIO_SODR = PIN_RELAY_1.mask;
	} else {
		PIN_RELAY_1.pio->PIO_CODR = PIN_RELAY_1.mask;
	}

	if(data->relay2) {
		PIN_RELAY_2.pio->PIO_SODR = PIN_RELAY_2.mask;
	} else {
		PIN_RELAY_2.pio->PIO_CODR = PIN_RELAY_2.mask;
	}

	BC->time[0] = 0;
	BC->time[1] = 0;
	BC->time_remaining[0] = 0;
	BC->time_remaining[1] = 0;
}

void get(uint8_t com, Get *data) {
	GetReturn gr = {
		data->stack_id,
		data->type,
		sizeof(GetReturn),
		PIN_RELAY_1.pio->PIO_ODSR & PIN_RELAY_1.mask,
		PIN_RELAY_2.pio->PIO_ODSR & PIN_RELAY_2.mask,
	};

	BA->send_blocking_with_timeout(&gr,
	                               sizeof(GetReturn),
	                               com);
}

void set_monoflop(uint8_t com, SetMonoflop *data) {
	if(data->relay != 1 && data->relay != 2) {
		// TODO: Error?
		return;
	}

	const uint8_t relay = data->relay-1;

	BC->time[relay] = data->time;
	BC->time_remaining[relay] = data->time;

	if(data->relay == 1) {
		if(data->state) {
			PIN_RELAY_1.pio->PIO_SODR = PIN_RELAY_1.mask;
		} else {
			PIN_RELAY_1.pio->PIO_CODR = PIN_RELAY_1.mask;
		}
	}

	if(data->relay == 2) {
		if(data->state) {
			PIN_RELAY_2.pio->PIO_SODR = PIN_RELAY_2.mask;
		} else {
			PIN_RELAY_2.pio->PIO_CODR = PIN_RELAY_2.mask;
		}
	}

}

void get_monoflop(uint8_t com, GetMonoflop *data) {
	if(data->relay != 1 && data->relay != 2) {
		// TODO: Error?
		return;
	}

	const uint8_t relay = data->relay-1;

	GetMonoflopReturn gfr;

	gfr.stack_id      = data->stack_id;
	gfr.type          = data->type;
	gfr.length        = sizeof(GetMonoflopReturn);
	gfr.time = BC->time[relay];
	gfr.time_remaining = BC->time_remaining[relay];
	if(data->relay == 1) {
		gfr.state = PIN_RELAY_1.pio->PIO_ODSR & PIN_RELAY_1.mask;
	} else {
		gfr.state = PIN_RELAY_2.pio->PIO_ODSR & PIN_RELAY_2.mask;
	}

	BA->send_blocking_with_timeout(&gfr, sizeof(GetMonoflopReturn), com);
}

void constructor(void) {
	BC->time[0] = 0;
	BC->time[1] = 0;
	BC->time_remaining[0] = 0;
	BC->time_remaining[1] = 0;
	BC->monoflop_callback[0] = false;
	BC->monoflop_callback[1] = false;

	PIN_RELAY_1.type = PIO_OUTPUT_0;
	PIN_RELAY_1.attribute = PIO_DEFAULT;
    BA->PIO_Configure(&PIN_RELAY_1, 1);

    PIN_RELAY_2.type = PIO_OUTPUT_0;
    PIN_RELAY_2.attribute = PIO_DEFAULT;
    BA->PIO_Configure(&PIN_RELAY_2, 1);
}

void destructor(void) {
	PIN_RELAY_1.type = PIO_INPUT;
	PIN_RELAY_1.attribute = PIO_PULLUP;
    BA->PIO_Configure(&PIN_RELAY_1, 1);

    PIN_RELAY_2.type = PIO_INPUT;
    PIN_RELAY_2.attribute = PIO_PULLUP;
    BA->PIO_Configure(&PIN_RELAY_2, 1);
}

void tick(uint8_t tick_type) {
	if(tick_type & TICK_TASK_TYPE_CALCULATION) {
		if(BC->time_remaining[0] != 0) {
			BC->time_remaining[0]--;
			if(BC->time_remaining[0] == 0) {
				if(PIN_RELAY_1.pio->PIO_ODSR & PIN_RELAY_1.mask) {
					PIN_RELAY_1.pio->PIO_CODR = PIN_RELAY_1.mask;
				} else {
					PIN_RELAY_1.pio->PIO_SODR = PIN_RELAY_1.mask;
				}
				BC->monoflop_callback[0] = true;
			}
		}

		if(BC->time_remaining[1] != 0) {
			BC->time_remaining[1]--;
			if(BC->time_remaining[1] == 0) {
				if(PIN_RELAY_2.pio->PIO_ODSR & PIN_RELAY_2.mask) {
					PIN_RELAY_2.pio->PIO_CODR = PIN_RELAY_2.mask;
				} else {
					PIN_RELAY_2.pio->PIO_SODR = PIN_RELAY_2.mask;
				}
				BC->monoflop_callback[1] = true;
			}
		}
	}

	if(tick_type & TICK_TASK_TYPE_MESSAGE) {
		if(BC->monoflop_callback[0]) {
			MonoflopDone md = {
				BS->stack_id,
				TYPE_MONOFLOP_DONE,
				sizeof(MonoflopDone),
				1,
				PIN_RELAY_1.pio->PIO_ODSR & PIN_RELAY_1.mask
			};

			BA->send_blocking_with_timeout(&md,
										   sizeof(MonoflopDone),
										   *BA->com_current);

			BC->monoflop_callback[0] = false;
		}

		if(BC->monoflop_callback[1]) {
			MonoflopDone md = {
				BS->stack_id,
				TYPE_MONOFLOP_DONE,
				sizeof(MonoflopDone),
				2,
				PIN_RELAY_2.pio->PIO_ODSR & PIN_RELAY_2.mask
			};

			BA->send_blocking_with_timeout(&md,
										   sizeof(MonoflopDone),
										   *BA->com_current);

			BC->monoflop_callback[1] = false;
		}
	}
}

