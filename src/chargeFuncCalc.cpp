/*******************************************************************************
chargeFuncCalc.cpp - Align-it
 
Copyright 2012-2013 by Silicos-it, a division of Imacosi BVBA

This file is part of Align-it.

	Align-it is free software: you can redistribute it and/or modify
	it under the terms of the GNU Lesser General Public License as published 
	by the Free Software Foundation, either version 3 of the License, or
	(at your option) any later version.

	Align-it is distributed in the hope that it will be useful,
	but WITHOUT ANY WARRANTY; without even the implied warranty of
	MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
	GNU Lesser General Public License for more details.

	You should have received a copy of the GNU Lesser General Public License
	along with Align-it.  If not, see <http://www.gnu.org/licenses/>.

Align-it is linked against OpenBabel version 2.

	OpenBabel is free software; you can redistribute it and/or modify
	it under the terms of the GNU General Public License as published by
	the Free Software Foundation version 2 of the License.

***********************************************************************/



#include "chargeFuncCalc.h"
#include <openbabel/obiter.h>
#include <openbabel/atom.h>

void
chargeFuncCalc(OpenBabel::OBMol* m, Pharmacophore* pharmacophore)
{
	// Create for every non-zero formal charge a pharmacophore point
	int charge;
   	for(OpenBabel::OBMolAtomIter atom(m); atom; ++atom)
   	{
      	charge = atom->GetFormalCharge();
      	if (charge < 0)
      	{
         	PharmacophorePoint p;
         	p.func = NEGC;
         	p.point.x = atom->x();
         	p.point.y = atom->y();
         	p.point.z = atom->z();
         	p.alpha = funcSigma[NEGC];
         	p.hasNormal = false;
         	pharmacophore->push_back(p);
      	}
      	else if (charge > 0)
      	{
         	PharmacophorePoint p;
         	p.func = POSC;
         	p.point.x = atom->x();
         	p.point.y = atom->y();
         	p.point.z = atom->z();
         	p.alpha = funcSigma[POSC];
         	p.hasNormal = false;
         	pharmacophore->push_back(p);
      	}
   	}
}
