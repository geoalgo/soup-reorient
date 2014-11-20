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
#include "details/Off_save_visitor.h"




int main(int argc,char** argv){
	if(argc!=3){
		std::cerr <<"Usage ./"<<argv[0]<<" input.off output.off\n";
		std::cerr <<"To reorient Off mesh in input.off file and to save it into output.off file\n";
		return EXIT_FAILURE;
	}
	{
		//save the reoriented mesh in a off file argv[2]
		boost::progress_timer t;
		Reorient::reorient(Reorient::OFF_save_visitor(argv[2]),argv[1]);
		std::cout <<"elapsed time: ";
	}
}
