# -*- coding: utf-8 -*-

"""
/* Copyright 2012, Fan Wang(Parai)
 *
 * This file is part of GaInOS.
 *
 * GaInOS is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *             
 * Linking GaInOS statically or dynamically with other modules is making a
 * combined work based on GaInOS. Thus, the terms and conditions of the GNU
 * General Public License cover the whole combination.
 *
 * In addition, as a special exception, the copyright holders of GaInOS give
 * you permission to combine GaInOS program with free software programs or
 * libraries that are released under the GNU LGPL and with independent modules
 * that communicate with GaInOS solely through the GaInOS defined interface. 
 * You may copy and distribute such a system following the terms of the GNU GPL
 * for GaInOS and the licenses of the other code concerned, provided that you
 * include the source code of that other code when and as the GNU GPL requires
 * distribution of source code.
 *
 * Note that people who make modified versions of GaInOS are not obligated to
 * grant this special exception for their modified versions; it is their choice
 * whether to do so. The GNU General Public License gives permission to release
 * a modified version without this exception; this exception also makes it
 * possible to release a modified version which carries forward this exception.
 * 
 * GaInOS is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with GaInOS. If not, see <http://www.gnu.org/licenses/>.
 *
 */
/* |---------+-------------------| */
/* | Author: | Wang Fan(parai)   | */
/* |---------+-------------------| */
/* | Email:  | parai@foxmail.com | */
/* |---------+-------------------| */
"""
from Can_MC9S12DP512 import *
from CanIfCfg import *
from EcuCcfg import EcuCObj

ArObjDict_MC9S12DP512={'Adc':UnimplementError, 
                       'Can':CanObj_MC9S12DP512, 
                       'CanIf':CanIfObj, 
                       'CanNm':UnimplementError,
                       'CanTp':UnimplementError,
                       'CanSm':UnimplementError,
                       'Com':UnimplementError,
                       'Dio':UnimplementError,
                       'Eep':UnimplementError,
                       'EcuC':EcuCObj, 
                       'Fls':UnimplementError,
                       'Gpt':UnimplementError,
                       'Icu':UnimplementError,
                       'Pwm':UnimplementError,
                       'Port':UnimplementError,
                       'PduR':UnimplementError,
                       'Spi':UnimplementError,
                       'Wdg':UnimplementError,
                       'WdgIf':UnimplementError,
                       }
