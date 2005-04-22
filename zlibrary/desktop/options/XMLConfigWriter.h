/*
 * Copyright (C) 2005 Nikolay Pultsin <geometer@mawhrin.net>
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 675 Mass Ave, Cambridge, MA 02139, USA.
 */

#ifndef __XMLCONFIGWRITER_H__
#define __XMLCONFIGWRITER_H__

#include <stack>
#include <vector>
#include <string>

#include <abstract/ZLXMLWriter.h>

class XMLConfig;

class XMLConfigWriter : public ZLXMLWriter {

public:
	XMLConfigWriter(XMLConfig &config, ZLOutputStream &stream) : ZLXMLWriter(stream),  myConfig(config) {}
	void write();

private:
	XMLConfig &myConfig;
};

#endif /* __XMLCONFIGWRITER_H__ */
