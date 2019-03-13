/* Molly Viau
May 30 2018
Project 1
Console application to compile statistics on a list of integers

*/
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <iomanip>
#include <locale>


using namespace std;

}

/* Finds the lowest value element in the vector
parameter: vect (the vector to be used)
*/
double minValue(vector<double> vect)
{
	// set the value of the minimum value to the first element on the vector
	double min = vect[0];
	// loop through the vector
	for (size_t i = 1; i < vect.size(); i++)
	{
	// if the current element is smaller than min
	if (vect[i] < min)
	{
	// minimum value is updated
	min = vect[i];
	}
}
	// return the minimum value
return min;

} 
/* Finds the highest value element in the vector
parameter: vect (the vector to be used)
*/
double maxValue(vector<double> vect)
{
	// set the max variable to the first element
	double max = vect[0];
	// iterate through the vector
	for (size_t i = 1; i < vect.size(); i++)
	{
		// if the current element is higher than the max
		if (vect[i] > max) 
		{
			// assign that element as the new max
			max = vect[i];
		}
	}
	// return the highest element
	return max;
} 
/* Finds the median value in a vector
parameter: vect (the vector to be used)*/
double medValue(vector<double> vect)
{
	// set an unsigned int as the sizze of the vector
	size_t vectSize = vect.size();
	// check to see if the vector is empty
	if (vectSize == 0)
	{	// if the vector is empty
		return 0; 
	}
	else 
	{	// sort the vector
		sort(vect.begin(), vect.end());
		// check to see if the vector size is odd
		if (vectSize % 2 == 0)
		{
			// return the median value
			return (vect[vectSize / 2 - 1] + vect[vectSize / 2]) / 2;
		}
		// return the median value if the vector size is even
		return vect[vectSize / 2];
	}
}
/* Calculate the mean of a vector
parameter: vect (vector to be used)*/
double arithMeanValue(vector<double> vect)
{
	// set a sum variable
	double sum = 0; 
	// add all the elements together
	for (size_t i = 0; i < vect.size(); i++) sum += vect[i];
	// divide by the number of elements
	double mean = sum / vect.size();
	// return the mean
	return mean;
}
/*
Calculates the Mean Absolute Deviation
parameter: vect is the vector used*/
double absoluteDevMean(vector<double> vect)
{
	
	// find the mean of the vector	and the size
	double aMean = arithMeanValue(vect);
	size_t vectSize = vect.size();		
	double absVal = 0;

	for (size_t i = 0; i < vectSize; i++) 
	{
		// find the sum of the absolute values of the differences
		// find the absolute value of the difference between each data value and the mean. data value - mean
		absVal += abs(vect[i] - aMean);
		
	}
	// divide the sum of the absolute values of the differences by the number of data values
	double result = absVal / vect.size();
	return result;

}
 /*
 Calculates the Median Absolute Deviation
 parameter: vect (vector to be used)*/
double absoluteDevMed(vector<double> vect)
{
	// find the median
	double aMedian = medValue(vect);
	// set a variable for the vector size
	size_t vectSize = vect.size();
	// create new vector with that size
	vector<double> newVect (vectSize);
	for (size_t i = 0; i < vectSize; i++)
	{  
		// subtract this median from each value in vector
		// store the differences in a new vector
		newVect[i] = abs(vect[i] - aMedian);	
	}
	// find the median of these absolute differences
	double result = medValue(newVect);
	return result;

}
/* Calculates the variance of the vector
parameter: vect (vector to be used)*/
double variance(vector<double> vect)
{
	// set variable for vector size
 	size_t vectSize = vect.size();
	// create two new variables
	vector<double> newVect(vectSize);
	vector<double> newVect2(vectSize);
	// find the mean
	double mean = arithMeanValue(vect);
	// subtract the mean and square the result for each value
	for (size_t i = 0; i < vectSize; i++)
	{
		newVect2[i] = (abs(vect[i] - mean));
		newVect[i] = newVect2[i] * newVect2[i];
	}
	// find the mean of those squared differences
	double meanSquared = arithMeanValue(newVect);
	double result = meanSquared;
	return result;
} 
/* Calculates the standard deviation
parameter: vect (vector to be used)*/
double stanDev(vector<double> vect)
{
	// set a variable for vector size and create two vectors with it
	size_t vectSize = vect.size();
	vector<double> newVect(vectSize);
	vector<double> newVect2(vectSize);
	// find the mean
	double mean = arithMeanValue(vect);
	// subtract the mean and square the result for each value
	for (size_t i = 0; i < vectSize; i++)
	{
		newVect2[i] = (abs(vect[i] - mean));
		newVect[i] = newVect2[i] * newVect2[i];
	}
	// find the mean of those squared differences
	double meanSquared = arithMeanValue(newVect);
	// take the square root of that
	double result = sqrt(meanSquared);
	return result;

}
vector<double> calculateMode(vector<double> vect)
{
	// sort the vector
	sort(vect.begin(), vect.end());

	// set a counter
	size_t counter = 1;

	// set a max value for number of elements
	double max = 0;

	// set a mode variable as the first element of the vector
	double mode = vect[0];

	// make a variable for the vect size
	double vectSize = vect.size();
	// create a vector to hold the modes (if there is more than one)
	vector<double> modesVect;
	// set an unsigned iterator variable
	size_t pass;
	// iterate through the vector
	for (pass = 0; pass < vectSize - 1; pass++)
	{   // if the iterated value is the same as the next value
		if (vect[pass] == vect[pass + 1])
		{
			// increment the counter
			counter++;
			// if the counter is more than the max, then the max is the counter and the current element is the mode
			if (counter > max)
			{  // put the element in the mode and clear the old modes
				max = counter;
				modesVect.clear();
				modesVect.push_back(vect[pass]);
			}// put element into the mode vector
			else if (counter == max)
			{
				modesVect.push_back(vect[pass]);
			}
		}
		else
		{
			counter = 1; // reset counter.
		}
	}
		// return the vector of modes
		return modesVect;
	
}
/* Calculate the Mode Absolute Deviation
 parameter: vect (vector to be used)*/
double absoluteDevMode(vector<double> vect)
{
	// find the mode
	vector<double> aModeVec = calculateMode(vect);
	double aMode = aModeVec[0];
	size_t vectSize = vect.size();
	vector<double> newVect(vectSize);
	for (size_t i = 0; i < vectSize; i++)
	{
		// subtract this mode from each value in vector
		// store the differences in a new vector
		newVect[i] = abs(vect[i] - aMode);
	}
	// find the mean of these absolute differences
	double result = arithMeanValue(newVect);
	return result;
}


/* Displays the freqency distribution using 10 bins for the vector
parameter: vect (vector to be used)*/
void freqDist(vector<double> vect)
		{
			size_t vectSize = vect.size();
			// sort the elements from highest to lowest
			sort(vect.begin(), vect.end());

			// find the highest element
			double highest = vect[vectSize - 1];

			// find the bin size by dividing the highest element by ten
			double binSize = highest / 10;

			// calculate the range for each bin size
			double bin100 = highest * 1.0097;
			double bin10 = (highest - binSize) * 1.0097;
			double bin9 = (highest - (binSize * 2)) * 1.0097;
			double bin8 = (highest - (binSize * 3)) * 1.0097;
			double bin7 = (highest - (binSize * 4)) * 1.0097;
			double bin6 = (highest - (binSize * 5)) * 1.0097;
			double bin5 = (highest - (binSize * 6)) * 1.0097;
			double bin4 = (highest - (binSize * 7)) * 1.0097;
			double bin3 = (highest - (binSize * 8)) * 1.0097;
			double bin2 = (highest - (binSize * 9)) * 1.0097;
			double bin1 = (highest - (binSize * 10)) * 1.0097;
			// initialize count variables
			int count1 = 0;
			int count2 = 0;
			int count3 = 0;
			int count4 = 0;
			int count5 = 0;
			int count6 = 0;
			int count7 = 0;
			int count8 = 0;
			int count9 = 0;
			int count10 = 0;
		

	for (size_t i = 0; i < vectSize; i++)
	{
		// add the variables and increment
		if (vect[i] >= bin1 && vect[i] < bin2)
			count1 = count1 + 1;
		if (vect[i] >= bin2 && vect[i] < bin3)
			count2 = count2 + 1;
		if (vect[i] >= bin3 && vect[i] < bin4)
			count3 = count3 + 1;
		if (vect[i] >= bin4 && vect[i] < bin5)
			count4 = count4 + 1;
		if (vect[i] >= bin5 && vect[i] < bin6)
			count5 = count5 + 1;
		if (vect[i] >= bin6 && vect[i] < bin7)
			count6 = count6 + 1;
		if (vect[i] >= bin7 && vect[i] < bin8)
			count7 = count7 + 1;
		if (vect[i] >= bin8 && vect[i] < bin9)
			count8 = count8 + 1;
		if (vect[i] >= bin9 && vect[i] < bin10)
			count9 = count9 + 1;
		if (vect[i] >= bin10 && vect[i] < bin100)
			count10 = count10 + 1;
	}
	
	// set precision to 2 decimal places
	cout << fixed;
	cout << setprecision(2);

	double count1P = (double)count1 / (double)vectSize;
	double count2P = (double)count2 / (double)vectSize;
	double count3P = (double)count3 / (double)vectSize;
	double count4P = (double)count4 / (double)vectSize;
	double count5P = (double)count5 / (double)vectSize;
	double count6P = (double)count6 / (double)vectSize;
	double count7P = (double)count7 / (double)vectSize;
	double count8P = (double)count8 / (double)vectSize;
	double count9P = (double)count9 / (double)vectSize;
	double count10P = (double)count10 / (double)vectSize;

	// print everything out
	cout << "\n\n[   " << bin1 << "..   " << bin2 << " > = " << count1 << " : " << count1P << endl;
	cout << "[   " << bin2 << "..   " << bin3 << " > = " << count2 << " : " << count2P << endl;
	cout << "[   " << bin3 << "..   " << bin4 << " > = " << count3 << " : " << count3P << endl;
	cout << "[   " << bin4 << "..   " << bin5 << " > = " << count4 << " : " << count4P << endl;
	cout << "[   " << bin5 << "..   " << bin6 << " > = " << count5 << " : " << count5P << endl;
	cout << "[   " << bin6 << "..   " << bin7 << " > = " << count6 << " : " << count6P << endl;
	cout << "[   " << bin7 << "..   " << bin8 << " > = " << count7 << " : " << count7P << endl;
	cout << "[   " << bin8 << "..   " << bin9 << " > = " << count8 << " : " << count8P << endl;
	cout << "[   " << bin9 << "..   " << bin10 << " > = " << count9 << " : " << count9P << endl;
	cout << "[   " << bin10 << "..   " << bin100 << " > = " << count10 << " : " << count10P << endl;

}  
/* Displays the quintiles for the vector
parameter: vect (vector to be used)
*/
void quintile(vector<double> vect)
{
	size_t vectSize = vect.size();
	// sort the elements from highest to lowest
	sort(vect.begin(), vect.end());
	// take the highest element and divide it by 5
	// each quintile is this size
	double highest = vect[vectSize - 1];
	double quintileSize = highest / 5;

	// set each quintile size as a multiple of the quintileSize
	double quintile0 = 0;
	double quintile1 = quintile0 + quintileSize;
	double quintile2 = quintile1 + quintileSize;
	double quintile3 = quintile2 + quintileSize;
	double quintile4 = quintile3 + quintileSize;
	double quintile5 = quintile4 + quintileSize;

	double count1 = 0;
	double count2 = 0;
	double count3 = 0;
	double count4 = 0;
	double count5 = 0;

	for (size_t i = 0; i < vectSize; i++)
	{
		if (vect[i] > quintile0 && vect[i] <= quintile1)
			count1 = count1 + 1;
		if (vect[i] > quintile1 && vect[i] <= quintile2)
			count2 = count2 + 1;
		if (vect[i] > quintile2 && vect[i] <= quintile3)
			count3 = count3 + 1;
		if (vect[i] > quintile3 && vect[i] <= quintile4)
			count4 = count4 + 1;
		if (vect[i] > quintile4 && vect[i] <= quintile5)
			count5 = count5 + 1;
	}
	double sum1 = 0;
	double sum2 = 0;
	double sum3 = 0;
	double sum4 = 0;
	double sum5 = 0;

	for (size_t i = 0; i < vectSize; i++)
	{
		if (vect[i] > quintile0 && vect[i] <= quintile1)
			sum1 += vect[i];
		if (vect[i] > quintile1 && vect[i] <= quintile2)
			sum2 += vect[i];
		if (vect[i] > quintile2 && vect[i] <= quintile3)
			sum3 += vect[i];
		if (vect[i] > quintile3 && vect[i] <= quintile4)
			sum4 += vect[i];
		if (vect[i] > quintile4 && vect[i] <= quintile5)
			sum5 += vect[i];
	}

	double mean1 = sum1 / count1;
	double mean2 = sum2 / count2;
	double mean3 = sum3 / count3;
	double mean4 = sum4 / count4;
	double mean5 = sum5 / count5;

	cout << "\nQuintile means" << endl;
	cout << "Q1: " << mean1 << " [" << quintile0 << ".." << quintile1 << ">" << endl;
	cout << "Q2: " << mean2 << " [" << quintile1 << ".." << quintile2 << ">" << endl;
	cout << "Q3: " << mean3 << " [" << quintile2 << ".." << quintile3 << ">" << endl;
	cout << "Q4: " << mean4 << " [" << quintile3 << ".." << quintile4 << ">" << endl;
	cout << "Q5: " << mean5 << " [" << quintile4 << ".." << quintile5 << ">" << endl;
} 
// displays the number of outliers greater/less than 2 and 3 standard deviations away from the mean
void outlier(vector<double> vect)
{	// set variables and calculate standard deviation and mean
	double vectSize = vect.size();
	double stanDevi = stanDev(vect);
	double mean = arithMeanValue(vect);
	
	size_t high2Outliers = 0;
	size_t high3Outliers = 0;
	size_t low2Outliers = 0;
	size_t low3Outliers = 0;
	sort(vect.begin(), vect.end());
	// iterate through the vector to find the outliers that are 2 standevs higher than the mean
	double out2 = mean + (2 * stanDevi);
	double out3 = mean + (3 * stanDevi);
	double out22 = mean - (2 * stanDevi);
	double out33 = mean - (3 * stanDevi);

	for (size_t i = 0; i < vectSize; i++)
	{		
		// high2Outliers =(number of values greater than) mean + 2 * standard deviation
		if (vect[i] > out2)
			high2Outliers++;
		// high3Outliers = (number of values greater than) mean + 3 * standard deviation
		if (vect[i] > out3)
			high3Outliers++;
		// low2Outliers = (number of values less than) mean + 2 * standard deviation
		if (vect[i] < out22)
			low2Outliers++;
		// outliers 3 = (number of values less than) (mean + 3 * standard deviation)
		if (vect[i] < out33)
			low3Outliers++;
	}
	cout << fixed;
	cout << setprecision(2);

	// calculate percentages of values that are outliers
	double low3OutliersP = low3Outliers / vect.size() * 100;
	double low2OutliersP = low2Outliers / vect.size() * 100;
	double high2OutliersP = high2Outliers / vect.size() * 100;
	double high3OutliersP = high3Outliers / vect.size() * 100;

	cout << "\nOutliers";
	cout << "\n--------";
	cout << "\n<= 3 dev below: " << low3Outliers << " (" << low3OutliersP << "%)";
	cout << "\n<= 2 dev below: " << low2Outliers << " (" << low2OutliersP << "%)";
	cout << "\n>= 2 dev above: " << high2Outliers << " (" << high2OutliersP << "%)";
	cout << "\n>= 3 dev above: " << high3Outliers << " (" << high3OutliersP << "%)";
} 


int main()
{
	// set the locale
	locale here("");
	cout.imbue(here);
	// set floating point precision to 3 decimals
	cout << fixed;
	cout << setprecision(3);
	// my test vector
    //vector<double> vect{1,2, 3, 3, 4, 5, 6, 7, 8, 9, 10};
	cout << "Stats Program\nMolly Viau 2018(c)" << endl;
	cout << "Enter white space seperated data values terminated by ^Z" << endl;
	vector<double> vect;
	double num;
	while (cin >> num) // will stop when end of file is reached or ^Z
	{
		vect.push_back(num);
	}
	
	// Find the vector size and assign it to a variable
	double vectSize = vect.size();
	cout << "Results:\n" << "N = " << vectSize;
	
	double resultMin = minValue(vect);
	cout << "\nMin = " << resultMin; 
	
	double resultMax = maxValue(vect);
	cout << "\nMax = " << resultMax; 

	double resultMean = arithMeanValue(vect);
	cout << "\nArithmetic Mean is = " << resultMean;

	double resultMed = medValue(vect);
	cout << "\nStatistical Median = " << resultMed; 

	vector<double> modesVect = calculateMode(vect);

	
	cout << "\nMode: < ";
	for (size_t x = 0; x != modesVect.size(); ++x)
	{
		size_t g = 1;
		if (modesVect.size() == g)
		{
			cout << modesVect[x];
			double devMode = absoluteDevMode(vect);
			cout << " >";
			cout << "\nMode absolute deviation: < " << devMode;
		}
		else if (modesVect.size() > 1)
		{
			cout << modesVect.at(x);
			cout << ", ";

		}
	}

		
	

	double resultAbsDevMe = absoluteDevMean(vect);
	cout << "\nMean absolute deviation = " << resultAbsDevMe;

	double resultAbsDevMed = absoluteDevMed(vect);
	cout << "\nMedian absolute deviation = " << resultAbsDevMed; 

	
	double resultVar = variance(vect);
	cout << "\nVariance = " << resultVar;

	double resultStanDev = stanDev(vect);
	cout << "\nStandard deviation = " << resultStanDev << endl;

	freqDist(vect);

	quintile(vect);
	
	outlier(vect);
}
