/**
 * Copyright (c) 2017 Ivelin Yanev <bgfortran@gmail.com>.
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS
 * FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License along with
 * this program; if not, write to the Free Software Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA 02110, USA
 **/

//============================================================================
// Name        : Node.h
// Author      : Ivelin Ynev <bgfortran@gmail.com>
// Version     : 1.0
// Since       : 2017
// Description :
//============================================================================
#ifndef NODE_H_
#define NODE_H_

#if ARDUINO >= 100
#include "Arduino.h"
#else
//TODO
#endif

#include <stdint.h>

#define FROM_LOW 1023
#define FROM_HIGH 114
#define TO_LOW 0
#define TO_HIGH 100

class Node {

private:
	int soilValuel;
	uint8_t soilPin;
	uint8_t dhtPin;
	//struct dht_data;

public:
	struct dht_data {
		float humidity;
		float temperature;
		float heatIndex;
	};
	/**
	 * The default constructor with parameters.
	 *
	 * @param soilPin The pin for Soil Moisture Sensor.
	 */
	Node(uint8_t soilPin, uint8_t dhtPin);

	/**
	 * Read  soil humanidity from soild sensor. The possible values that can
	 * be measured are the following:
	 *
	 * MIN Value: 0 - completely dry substance
	 * MAX Value: 100 - water
	 **/
	uint16_t readSoilHumidity();

	/**
	 *
	 */
	struct dht_data readDHT();

};

#endif /* NODE_H_ */

