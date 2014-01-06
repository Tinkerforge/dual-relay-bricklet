/* dual-relay
 * Copyright (C) 2011-2013 Olaf Lüke <olaf@tinkerforge.com>
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

void invocation(const ComType com, const uint8_t *data) {
	switch(((MessageHeader*)data)->fid) {
		case FID_SET: {
			set(com, (Set*)data);
			return;
		}

		case FID_GET: {
			get(com, (Get*)data);
			return;
		}

		case FID_SET_MONOFLOP: {
			set_monoflop(com, (SetMonoflop*)data);
			return;
		}

		case FID_GET_MONOFLOP: {
			get_monoflop(com, (GetMonoflop*)data);
			return;
		}

		case FID_SET_SELECTED_STATE: {
			set_selected_state(com, (SetSelectedState*)data);
			return;
		}

		default: {
			BA->com_return_error(data, sizeof(MessageHeader), MESSAGE_ERROR_CODE_NOT_SUPPORTED, com);
			return;
		}
	}
}

void set(const ComType com, const Set *data) {
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

	BA->com_return_setter(com, data);
}

void get(const ComType com, const Get *data) {
	GetReturn gr;
	gr.header        = data->header;
	gr.header.length = sizeof(GetReturn);
	gr.relay1        = PIN_RELAY_1.pio->PIO_ODSR & PIN_RELAY_1.mask;
	gr.relay2        = PIN_RELAY_2.pio->PIO_ODSR & PIN_RELAY_2.mask;

	BA->send_blocking_with_timeout(&gr,
	                               sizeof(GetReturn),
	                               com);
}

void set_monoflop(const ComType com, const SetMonoflop *data) {
	if(data->relay != 1 && data->relay != 2) {
		BA->com_return_error(data, sizeof(MessageHeader), MESSAGE_ERROR_CODE_INVALID_PARAMETER, com);
		return;
	}

	const uint8_t relay = data->relay - 1;

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

	BA->com_return_setter(com, data);
}

void get_monoflop(const ComType com, const GetMonoflop *data) {
	if(data->relay != 1 && data->relay != 2) {
		BA->com_return_error(data, sizeof(GetMonoflopReturn), MESSAGE_ERROR_CODE_INVALID_PARAMETER, com);
		return;
	}

	const uint8_t relay = data->relay - 1;

	GetMonoflopReturn gfr;
	gfr.header        = data->header;
	gfr.header.length = sizeof(GetMonoflopReturn);

	gfr.time = BC->time[relay];
	gfr.time_remaining = BC->time_remaining[relay];
	if(data->relay == 1) {
		gfr.state = PIN_RELAY_1.pio->PIO_ODSR & PIN_RELAY_1.mask;
	} else {
		gfr.state = PIN_RELAY_2.pio->PIO_ODSR & PIN_RELAY_2.mask;
	}

	BA->send_blocking_with_timeout(&gfr, sizeof(GetMonoflopReturn), com);
}

void set_selected_state(const ComType com, const SetSelectedState *data) {
	if(data->relay == 1) {
		BC->time[0] = 0;
		BC->time_remaining[0] = 0;
		if(data->state) {
			PIN_RELAY_1.pio->PIO_SODR = PIN_RELAY_1.mask;
		} else {
			PIN_RELAY_1.pio->PIO_CODR = PIN_RELAY_1.mask;
		}
	} else if(data->relay == 2) {
		BC->time[1] = 0;
		BC->time_remaining[1] = 0;
		if(data->state) {
			PIN_RELAY_2.pio->PIO_SODR = PIN_RELAY_2.mask;
		} else {
			PIN_RELAY_2.pio->PIO_CODR = PIN_RELAY_2.mask;
		}
	} else {
		BA->com_return_error(data, sizeof(GetMonoflopReturn), MESSAGE_ERROR_CODE_INVALID_PARAMETER, com);
		return;
	}

	BA->com_return_setter(com, data);
}

void constructor(void) {
	_Static_assert(sizeof(BrickContext) <= BRICKLET_CONTEXT_MAX_SIZE, "BrickContext too big");

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

void tick(const uint8_t tick_type) {
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
			MonoflopDone md;
			BA->com_make_default_header(&md, BS->uid, sizeof(MonoflopDone), FID_MONOFLOP_DONE);
			md.relay = 1;
			md.state = PIN_RELAY_1.pio->PIO_ODSR & PIN_RELAY_1.mask;

			BA->send_blocking_with_timeout(&md,
										   sizeof(MonoflopDone),
										   *BA->com_current);

			BC->monoflop_callback[0] = false;
		}

		if(BC->monoflop_callback[1]) {
			MonoflopDone md;
			BA->com_make_default_header(&md, BS->uid, sizeof(MonoflopDone), FID_MONOFLOP_DONE);
			md.relay = 2;
			md.state = PIN_RELAY_2.pio->PIO_ODSR & PIN_RELAY_2.mask;

			BA->send_blocking_with_timeout(&md,
										   sizeof(MonoflopDone),
										   *BA->com_current);

			BC->monoflop_callback[1] = false;
		}
	}
}

