/*************************************************************
 * This file was automatically generated on 2011-08-23.      *
 *                                                           *
 * If you have a bugfix for this file and want to commit it, *
 * please fix the bug in the generator. You can find a link  *
 * to the generator git on tinkerforge.com                   *
 *************************************************************/

#include "bricklet_dual_relay.h"

#include <string.h>

#define TYPE_SET_STATE 1
#define TYPE_GET_STATE 2


#ifdef _MSC_VER
	#pragma pack(push)
	#pragma pack(1)

	#define PACKED
#else
	#define PACKED __attribute__((packed))
#endif

typedef struct {
	uint8_t stack_id;
	uint8_t type;
	uint16_t length;
	bool relay1;
	bool relay2;
} PACKED SetState;

typedef struct {
	uint8_t stack_id;
	uint8_t type;
	uint16_t length;
} PACKED GetState;

typedef struct {
	uint8_t stack_id;
	uint8_t type;
	uint16_t length;
	bool relay1;
	bool relay2;
} PACKED GetStateReturn;

#ifdef _MSC_VER
	#pragma pack(pop)
#endif

int dual_relay_set_state(DualRelay *dual_relay, bool relay1, bool relay2) {
	if(dual_relay->ipcon == NULL) {
		return E_NOT_ADDED;
	}

	ipcon_sem_wait_write(dual_relay);

	SetState ss;
	ss.stack_id = dual_relay->stack_id;
	ss.type = TYPE_SET_STATE;
	ss.length = sizeof(SetState);
	ss.relay1 = relay1;
	ss.relay2 = relay2;

	ipcon_device_write(dual_relay, (char *)&ss, sizeof(SetState));

	ipcon_sem_post_write(dual_relay);

	return E_OK;
}

int dual_relay_get_state(DualRelay *dual_relay, bool *ret_relay1, bool *ret_relay2) {
	if(dual_relay->ipcon == NULL) {
		return E_NOT_ADDED;
	}

	ipcon_sem_wait_write(dual_relay);

	dual_relay->answer.type = TYPE_GET_STATE;
	dual_relay->answer.length = sizeof(GetStateReturn);
	GetState gs;
	gs.stack_id = dual_relay->stack_id;
	gs.type = TYPE_GET_STATE;
	gs.length = sizeof(GetState);

	ipcon_device_write(dual_relay, (char *)&gs, sizeof(GetState));

	if(ipcon_answer_sem_wait_timeout(dual_relay) != 0) {
		ipcon_sem_post_write(dual_relay);
		return E_TIMEOUT;
	}

	GetStateReturn *gsr = (GetStateReturn *)dual_relay->answer.buffer;
	*ret_relay1 = gsr->relay1;
	*ret_relay2 = gsr->relay2;

	ipcon_sem_post_write(dual_relay);

	return E_OK;
}

void dual_relay_register_callback(DualRelay *dual_relay, uint8_t cb, void *func) {
    dual_relay->callbacks[cb] = func;
}

void dual_relay_create(DualRelay *dual_relay, const char *uid) {
	ipcon_device_create(dual_relay, uid);

}
