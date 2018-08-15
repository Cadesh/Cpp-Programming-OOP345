//-----------------------------------------------------------
//author: Andre R
//std number:
//workshop: OOP345 workshop 7
//date: 16 JUL 2018
//-----------------------------------------------------------

#ifndef DATATABLE_H					// avoid repeated expansion
#define DATATABLE_H


#include <iostream>
#include <iomanip> //otherwise gives error in linux for setw()
#include <fstream> //otherwise will get a warning in linux
#include <vector>
#include <cmath> // sqrt, pow
#include <algorithm> // sort
#include <numeric>   // accumulate, inner_product

//1 - copy data from a file into a sequential container OK
//2 - accumulate data values using the STL's numeric library OK
//3 - specify an operation on each value in a data set using a lambda expression OK
//4 - sort the data values in a data set using the STL's algorithm OK

using namespace std;
namespace w8 {


	///@class DataTable
	///@brief this class has two arrays that are used for statistical operations as mean, median, sigma and deviation
	template <typename T>
	class DataTable {

	private:
		int mDec; /// @brief number of decimals to be displayed
		int mWid; /// @brief width in characters to be displayed
		vector<T> coordX; /// @brief holds independent value (X coordinate)
		vector<T> coordY; /// @brief holds dependent value (Y coordinate)

	public:
		DataTable() = delete; /// Cant use default constructor
	    
		//-------------------------------------------------
		/// @brief Construtor with 3 parameters
		//-------------------------------------------------
		DataTable(ifstream &fs, int fwidth, int decimals) {
			this->mDec = decimals;
			this->mWid = fwidth;
			T cdX, cdY;
			while (fs.good())  { //this will take duplicate lines at the end of vector if there is a blank line at the end of the file
				fs >> cdX >> cdY;
				this->coordX.push_back(cdX);
				this->coordY.push_back(cdY);
			} 
			fs.close();
		} 
		//--------------------------------------------------
		
		//--------------------------------------------------
		/// @brief returns the mean value of the dependent coordinate
		/// according to the formula zmean = (Σizi) / n
		//--------------------------------------------------
		T mean() const {
			T n = coordY.size();
			T sum = accumulate(coordY.begin(), coordY.end(), 0.0);
			return (sum / n);
		}
		//--------------------------------------------------

		//--------------------------------------------------
		/// @brief returns the standard deviation (ssd) of the dependent coordinates
		/// ssd = squareRoot{ [ Σi(zi - zmean)^2 ] / (n - 1) }
		//--------------------------------------------------
		T sigma() const {
			T zMean = this->mean(); //calculate mean for the formula
			T dev = 0;

			int n = coordY.size();
			for (int i = 0; i < coordY.size(); i++) {
				dev += pow( coordY[i] - zMean, 2); // (value - mean)^2
			}
			dev = dev / (T)(n - 1);
			dev = sqrt(dev); // square root
			return dev;
		}
		//----------------------------------------------------

		//----------------------------------------------------
		/// @brief returns the median value of the dependent coordinate
		/// it is necessary to sort the vector to find the median
		//----------------------------------------------------
		T median() const {
		    //sort the coordY vector
			vector <T> lvec = this->coordY;

			//Lambda from OOP345 website https://scs.senecac.on.ca/~oop345/pages/content/algor.html
			std::sort(lvec.begin(), lvec.end(), [](T i, T j) { return i > j; }); 

			//now get the element in the middle
			//the median in the number that divides the sample in the middle
			int quant = lvec.size();
		
			//T median = (lvec[(quant / 2) - 1] + lvec[quant / 2]) / 2;
			T median = lvec[round(quant / 2)];
		
			return median;
		}
		//----------------------------------------------------

		//----------------------------------------------------
		/// returns the slope and intercept for the data set
		/// slope - the slope of the line in the x-y plane
		/// y_intercept - the y value of the line where it crosses the y - axis
		///@brief formula  slope = [ n ( Σixiyi ) - Σixi Σiyi ] / [ n (Σixi^2) - (Σixi)^2 ]
		/// formula y_intercept = [Σiyi - slope * Σixi] / n
		//----------------------------------------------------
		void regression(T& slope, T& y_intercept) const {
			T sumX, sumY;
			T inProdXX, inProdXY;
			int n = coordX.size();
			    // for the Σixi Σiyi (Sigma) sum up of values in vector we use std::accumulate
				sumX = accumulate(coordX.begin(), coordX.end(), (T)0);
				sumY = accumulate(coordY.begin(), coordY.end(), (T)0);
				// to solve the Σixiyi and Σixi^2 part of the formula we use std::inner_product
				inProdXX = inner_product(coordX.begin(), coordX.end(), coordX.begin(), (T)0.0);
				inProdXY = inner_product(coordX.begin(), coordX.end(), coordY.begin(), (T)0.0);
			
			slope = ((n * inProdXY) - (sumX * sumY)) / ((n * inProdXX) - pow(sumX,2));
			y_intercept = (sumY - (slope * sumX)) / n;
		}
		//----------------------------------------------------
		
   	    //----------------------------------------------------
		///@brief inserts the data generated by display() into the output stream
		//----------------------------------------------------
		friend ostream& operator<<(ostream& os, const DataTable& dt) {
		
			os << setw(dt.mWid) << setprecision(dt.mDec) << fixed << 'X';
			os << setw(dt.mWid) << 'Y' << endl;

			int size = dt.coordX.size();
			for (int i = 0; i < size; i++) {
				os << setw(dt.mWid) << dt.coordX[i];
				os << setw(dt.mWid) << dt.coordY[i] << endl;
			}
			return os;
		}
		//------------------------------------------------------
	}; //end of class

}

#endif