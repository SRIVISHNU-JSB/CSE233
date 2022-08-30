#include "stdafx.h"
#include "iostream"
using namespace std;
/////////////////////////////////////////////////////////////////////////////////////////
class angle
{
            private:
                        int degrees;     float mints;      char direc;
            public:
                        angle( int deg, float m, char dir ): degrees(deg), mints(m), direc(dir)   {/*Empty Body*/}                                         void get_angle( )
                        {           cout << "Enter Degrees, Minutes & Dirrection (i.e. E, W, S, N) Respectively: ";
                                                cin >> degrees >> mints >> direc;
                        }
                        void show_angle( ) const
                        {           cout << degrees << "\xF8" << mints << "' " << direc << endl;           }
};
/////////////////////////////////////////////////////////////////////////////////////////
void main( )
{
            angle angle1(50,55.2,'E');
            cout << "Default Value of Angle is: ";             angle1.show_angle( );
            angle1.get_angle( );
            cout << "Your Provided Value of Angle is: ";  angle1.show_angle( );
            system("pause");
}