/*************************************************************
 * This file was automatically generated on 23.08.2011.      *
 *                                                           *
 * If you have a bugfix for this file and want to commit it, *
 * please fix the bug in the generator. You can find a link  *
 * to the generator git on tinkerforge.com                   *
 *************************************************************/

#ifndef BRICKLET_DUAL_RELAY_H
#define BRICKLET_DUAL_RELAY_H

#include "ip_connection.h"

typedef Device DualRelay;


void dual_relay_create(DualRelay *dual_relay, const char *uid);

int dual_relay_set_state(DualRelay *dual_relay, bool relay1, bool relay2);
int dual_relay_get_state(DualRelay *dual_relay, bool *ret_relay1, bool *ret_relay2);

void dual_relay_register_callback(DualRelay *dual_relay, uint8_t cb, void *func);

#endif