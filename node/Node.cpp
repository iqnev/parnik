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
// Name        : Node.cpp
// Author      : Ivelin Ynev <bgfortran@gmail.com>
// Version     : 1.0
// Since       : 2017
// Description :
//============================================================================
#include "Node.h"

Node::Node(uint8_t _soilPin, uint8_t _dhtPin) {
	soilPin = _soilPin;
	dhtPin = _dhtPin;
}

uint16_t Node:: readSoilHumidity() {
	uint16_t  sensorValue = 0;
	uint16_t  outputValue = 0;
	sensorValue = analogRead(soilPin);

	outputValue = map(sensorValue, FROM_LOW, FROM_HIGH, TO_LOW, TO_HIGH);


	 unsigned char byteArray[4];

	 // convert from an unsigned long int to a 4-byte array
	 byteArray[0] = (int)((outputValue >> 24) & 0xFF) ;
	 byteArray[1] = (int)((outputValue >> 16) & 0xFF) ;
	 byteArray[2] = (int)((outputValue >> 8) & 0XFF);
	 byteArray[3] = (int)((outputValue & 0XFF));

	 const int siz_ar = sizeof(byteArray) / sizeof(int);

	     for (int i = 0; i < 4; i++) {
	    	 Serial.print(" ");
	    	  char buffer [100];

	    	 Serial.print(itoa (byteArray[i],buffer,2));
	     }
	     Serial.println();


	return outputValue;
}

struct Node::dht_data Node::readDHT() {
	Node::dht_data d;

	d.humidity = 56.5;
	d.temperature = 34.4;

	return d;
}










