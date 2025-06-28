/* Copyright (C) 2012-2017 IBM Corp.
 * This program is Licensed under the Apache License, Version 2.0
 * (the "License"); you may not use this file except in compliance
 * with the License. You may obtain a copy of the License at
 *   http://www.apache.org/licenses/LICENSE-2.0
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License. See accompanying LICENSE file.
 */
#include <iostream>
#include <vector>
#include <iomanip>
#include <cassert>

using namespace std;


/**
 * @class Cube
 * @brief Indexing into a hypercube
 **/
class Cube {
private:
   vector<int> dims;  // dims[i] is the size along the i'th diemnsion
   vector<int> prods; // prods[i] = \prod_{j=i}^{n-1} dims[i]
   vector<int> data;
   long size;

   Cube();

public:
   Cube(const vector<int>& idims) {
      dims = idims;
      long n = dims.size();
      assert(n > 0);


      prods.resize(n+1);
      prods[n] = 1;
      for (long i = n-1; i >= 0; i--) {
         assert(dims[i] > 0);
         prods[i] = dims[i]*prods[i+1];
      }


      size = prods[0];
      data.resize(size);
      for (long i = 0; i < size; i++) data[i] = 0;
   }

   bool operator==(const Cube& that) const {
      return dims == that.dims && data == that.data;
   }

   bool operator!=(const Cube& that) const {
      return !(*this == that);
   }

   const vector<int>& getDims() const { return dims; }

   long getSize() const { return size; }

   long getNumDims() const { return dims.size(); }

   long getDim(long d) const { return dims.at(d); }

   long getCoord(long i, long d) const {
      assert(i >= 0 && i < size);

      return (i % prods.at(d)) / prods.at(d+1);
   }

   long addCoord(long i, long d, long offset) const {
      assert(i >= 0 && i < size);

      offset = offset % dims.at(d);
      if (offset < 0) offset += dims.at(d);

      long i_d = getCoord(i, d);
      long i_d1 = (i_d + offset) % dims.at(d);

      long i1 = i + (i_d1 - i_d) * prods.at(d+1);

      return i1;
   }

   int& at(long i) { return data.at(i); }

   const int& at(long i) const { return data.at(i); }

};

Cube simpleRotate(const Cube& c, long offset) {

   assert(offset >= 0);
   Cube c1(c.getDims());

   long size = c.getSize();

   for (long i = 0; i < size; i++) {
      c1.at((i+offset)%size) = c.at(i);
   }

   return c1;
}


int allrotate()
{
   vector<int> dims(5);
   dims[0] = 5;
   dims[1] = 4;
   dims[2] = 3;
   dims[3] = 3;
   dims[4] = 4;

   //Cube c(dims);
   //simpleRotate(c, 1);
   
   return 0;
}

