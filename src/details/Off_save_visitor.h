/**
* soup-reorient- Reorientation of triangle soups into 2-manifold meshes.
* This file Copyright (C) 2013-2014 David Salinas <reorient.100.sisisoyo@spamgourmet.com>
*
* This program is free software; you can redistribute it and/or
* modify it under the terms of the GNU General Public License
* as published by the Free Software Foundation; either version 3
* of the License, or (at your option) any later version.
*
* This program is distributed in the hope that it will be useful,
* but WITHOUT ANY WARRANTY; without even the implied warranty of
* MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
* GNU General Public License for more details.
*
* You should have received a copy of the GNU General Public License
* along with this program. If not, see <http://www.gnu.org/licenses/>.
*
* The maintainer of this program can be reached at reorient.100.sisisoyo@spamgourmet.com
**/

/*
 * Off_save_visitor.h
 *
 *  Created on: Nov 13, 2014
 *      Author: dsalinas
 */

#ifndef OFF_SAVE_VISITOR_H_
#define OFF_SAVE_VISITOR_H_

#include <fstream>
#include "typedefs.h"
#include "Triangle.h"

namespace Reorient{
using Reorient::Point;
/**
 * call order :
 * - init
 * - vertex for all vertices
 * - triangle for all triangles
 */
struct OFF_save_visitor{
	OFF_save_visitor(const std::string& name_file_out):name_file_out_(name_file_out){
	}

	~OFF_save_visitor(){
		std::cerr <<"close file\n";
		file_.close();
	}

	void init(unsigned num_vertices,unsigned num_faces,unsigned num_edges = 0) const{
		file_.open(name_file_out_.c_str());
		if (!file_.is_open())
			std::cerr << "could not open output file :"<<name_file_out_<<std::endl;
		else{
			file_<<"OFF\n";
		}

		file_<<num_vertices<<" "<<num_faces<<" "<<num_edges<<std::endl;
	}

	void vertex(const Point& p) const{
		for(auto x : p)
			file_<< x << " ";
		file_<<std::endl;
	}

	void triangle(const Triangle& t) const{
		file_<<"3 ";
		for(auto x : t)
			file_<< x << " ";
		file_<<std::endl;
	}
private:
	std::string name_file_out_;
	mutable std::ofstream file_;
};

}

#endif /* OFF_SAVE_VISITOR_H_ */
