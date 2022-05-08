#include <iostream>
#include <stdlib.h>     /* srand, rand */
#include <time.h>       /* time */
#include <fstream>
#include <string>

//#define INTERVAL 100000
using namespace std;

int main()
{
    bool to_txt = true;
    int INTERVAL = 100;
    unsigned long long int sample_size = 100000;//
    unsigned long long int i, k;
    double rand_x, rand_y, origin_dist, pi;
    unsigned long long int circle_points, square_points;
    double times_repeated = 100;//
    int range_l = 10000000;
    int range_r = 10000000;
    double percentage_jump = (100 / times_repeated) / (range_r / range_l);
    double percentage = 0;
    double avg_pi;
    int index = 1;
    string output = "Sample size: " + to_string(sample_size) + " points generated for each estimation\n";
    string outcsv = "Index, Number of estimations, Sample size, Estimated value\n";
    // Initializing rand()
    srand(time(NULL));

    // Total Random numbers generated = possible x
    // values * possible y values
    for (k = range_l; k <= range_r; k += range_l) {
        sample_size = k;
        avg_pi = 0;
        circle_points = 0;
        square_points = 0;
        for (int j = 0; j < times_repeated; ++j) {//multiple execution of main program
            for (i = 0; i < sample_size; ++i) {//main loop

            // Randomly generated x and y values
                rand_x = double(rand() % (INTERVAL + 1)) / INTERVAL;
                rand_y = double(rand() % (INTERVAL + 1)) / INTERVAL;

                // Distance between (x, y) from the origin
                origin_dist = rand_x * rand_x + rand_y * rand_y;

                // Checking if (x, y) lies inside the define
                // circle with R=1
                if (origin_dist <= 1)
                    ++circle_points;

                // Total number of points generated
                ++square_points;


                // estimated pi after this iteration
                pi = double(4 * circle_points) / square_points;

                // For visual understanding (Optional)
                //cout << rand_x << " " << rand_y << " " << circle_points
                    //<< " " << square_points << " - " << pi << endl << endl;

                // Pausing estimation for first 10 values (Optional)
                //if (i < 20)
                    //getchar();
            }

            // Final Estimated Value

            //cout << "Total of " << square_points << " points generated\nFinal Estimation of Pi = " << pi;
            avg_pi += pi;
            percentage += percentage_jump;
            cout << "Current progress: " << percentage << "% | Number of estimations done: " << j + 1 << " | Current average: " << avg_pi / (j + 1) << "\n";
            if (to_txt)
                output += to_string(j) + ". Estimation of Pi = " + to_string(pi) + "\n";

            //cout << unsigned long long int(INTERVAL * INTERVAL) << "\n" << (INTERVAL * INTERVAL) << "\n" << INTERVAL << "\n\n";
            //cout << "\n" << circle_points << "\n";
            //cout << ++circle_points << "\n";
            //printf("%lld", i);
        }

        avg_pi /= times_repeated;
        if (to_txt)
            output += "Average of those estimations is " + to_string(avg_pi);
        outcsv += to_string(index++) + ", " + to_string(int(times_repeated)) + ", " + to_string(sample_size) + ", " + to_string(avg_pi) + "\n";
    }
    if (to_txt) {
        ofstream myfile;
        if (!myfile)
        {
            std::cout << "Something failed while opening the file\n";
        }
        myfile.open("pidata.txt");
        myfile << output;
        myfile.close();
    }
    ofstream fakeSheet;
    if (!fakeSheet)
    {
        std::cout << "Something failed while opening the file\n";
    }
    fakeSheet.open("pidata.csv");
    fakeSheet << outcsv;
    fakeSheet.close();



    return 0;
}