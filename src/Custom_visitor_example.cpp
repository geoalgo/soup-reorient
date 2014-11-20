
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
 * Example.cpp
 *
 *  Created on: Nov 13, 2014
 *      Author: dsalinas
 */

#include <boost/progress.hpp>
#include "Reorient.h"
#include "details/Triangle.h"
#include "details/Off_save_visitor.h"

using namespace Reorient;

/**
 * Reorientation will call methods of this visitor in that order :
 * - init -> before anything is explored
 * - vertex -> for all vertices
 * - triangle -> for all triangles after being reoriented
 *
 * You can do what you want here such as writing the oriented mesh in a '.ply' file.
 */
struct Custom_visitor{
	void init(unsigned num_vertices,unsigned num_faces,unsigned num_edges = 0) const{
		std::cout<<"num vertices,faces,edges:"<<num_vertices<<" "<<num_faces<<" "<<num_edges<<std::endl;
	}

	void vertex(const Point& p) const{
		std::cout<<"see point:";
		for(auto x : p)
			std::cout<< x << " ";
		std::cout<<std::endl;
	}

	void triangle(const Triangle& t) const{
		std::cout<<"see triangle:";
		for(auto x : t)
			std::cout<< x << " ";
		std::cout<<std::endl;
	}
};



int main(int argc,char** argv){
	if(argc!=3){
		std::cerr <<"Usage ./"<<argv[0]<<" input.off \n";
		return EXIT_FAILURE;
	}
	boost::progress_timer t2;
	reorient(Custom_visitor(),argv[1]);
	std::cout <<"elapsed time: ";
}
