 /*    Copyright (c) 2010-2013, Delft University of Technology
 *    All rights reserved.
 *
 *    Redistribution and use in source and binary forms, with or without modification, are
 *    permitted provided that the following conditions are met:
 *      - Redistributions of source code must retain the above copyright notice, this list of
 *        conditions and the following disclaimer.
 *      - Redistributions in binary form must reproduce the above copyright notice, this list of
 *        conditions and the following disclaimer in the documentation and/or other materials
 *        provided with the distribution.
 *      - Neither the name of the Delft University of Technology nor the names of its contributors
 *        may be used to endorse or promote products derived from this software without specific
 *        prior written permission.
 *
 *    THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND ANY EXPRESS
 *    OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF
 *    MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE
 *    COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL,
 *    EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE
 *    GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED
 *    AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING
 *    NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED
 *    OF THE POSSIBILITY OF SUCH DAMAGE.
 *
 *    Changelog
 *      YYMMDD    Author            Comment
 *   
 *
 *    References
 *      
 *
 *    Notes
 *
 */

#include <iostream>
#include <string>
#include <Eigen/Core>
#include <gal_accsrps.h>
#include <iomanip>
#include <limits>


// Produces a set of benchmark data to be used in the solar radiation model used in Tudat
int main( ) 
{
    // 1 AU
    double au = 1.49598e11;

    // Solar radiation pressure at 1 AU
    double p = 4.56e-6;

    // Coefficient of Shadow Function
    double v = 1;

    // Position of central emitting body 
    double psun [] = {0, 0, 0};

    /* Dictionary of Variables
    psat - position of accelerating body
    area - effective area of accelerating body
    mass - mass of of accelerating body
    eps - emissitivity of accelerating body
    a - final acceleration vector of accelerating body. Note: Its initial value is arbitrary
    */

    // Test 1
    // Does not appear in the unit tests. Compares to earlier Ganeff unit test.
    double psat [] = {au, au, 0};
    double area = 0.5;
    double mass = 20.0;
    double eps = 0.21;
    double a [] = {0.0, 0.0, 0.0};

    std::cout << "Test 1" << std::endl;
    gal_accsrps(psat, psun, p, au, area, mass, eps, v, a);
    std::cout << std::setprecision( std::numeric_limits< double >::digits10 ) << -1.0*a[ 0 ]*mass << std::endl <<  "\n";


    // Test 2
    // Compute acceleration due to solar radiation against at 1 AU
    psat[0] = au;
    psat[1] = 0.0;
    psat[2] = 0.0;
    area = 2.0;
    eps = 0.3;
    mass = 4.0;
    a[0] = 0.0;
    a[1] = 0.0;
    a[2] = 0.0;

    std::cout << "Test 2" << std::endl;
    gal_accsrps(psat, psun, p, au, area, mass, eps, v, a);
    std::cout << std::setprecision( std::numeric_limits< double >::digits10 ) << -1.0*a[ 0 ] << std::endl;
    std::cout << std::setprecision( std::numeric_limits< double >::digits10 ) << -1.0*a[ 1 ] << std::endl;
    std::cout << std::setprecision( std::numeric_limits< double >::digits10 ) << -1.0*a[ 2 ] << std::endl << "\n";

    // Test 3
    // Compute acceleration due to solar radiation of dust at distance of Venus
    psat[0] = 0.732 * au;
    psat [1] = 0.732 * au;
    psat [2] = 0.732 * au;
    area = 0.005;
    eps = 0.5;
    mass = 0.0022;
    a[0] = 0.0;
    a[1] = 0.0;
    a[2] = 0.0;

    std::cout << "Test 3" << std::endl;
    gal_accsrps(psat, psun, p, au, area, mass, eps, v, a);
    std::cout << std::setprecision( std::numeric_limits< double >::digits10 ) << -1.0*a[ 0 ] << std::endl;
    std::cout << std::setprecision( std::numeric_limits< double >::digits10 ) << -1.0*a[ 1 ] << std::endl;
    std::cout << std::setprecision( std::numeric_limits< double >::digits10 ) << -1.0*a[ 2 ] << std::endl << "\n";

    // Test 4
    // Compute approximate force  due to solar radiation at approximate distance of Uranus
    psat[0] = 10.044 * au;
    psat [1] = 9.014 * au;
    psat [2] = 9.529 * au;
    area = 69939064094327.4;
    eps = 0.8;
    mass = 1.0;
    a[0] = 0.0;
    a[1] = 0.0;
    a[2] = 0.0;

    std::cout << "Test 4" << std::endl;
    gal_accsrps(psat, psun, p, au, area, mass, eps, v, a);
    std::cout << std::setprecision( std::numeric_limits< double >::digits10 ) << -1.0*a[ 0 ] << std::endl;
    std::cout << std::setprecision( std::numeric_limits< double >::digits10 ) << -1.0*a[ 1 ] << std::endl;
    std::cout << std::setprecision( std::numeric_limits< double >::digits10 ) << -1.0*a[ 2 ] << std::endl << "\n";


    //Test 5
    // Compute approximate force due to solar radiation pressure on outstretched hand at 1 AU
    // Physics for Scientists and Engineers by Giancoli Volume 2, pg 828, example 31-7
    psat[0] =  au;
    psat [1] = 0.0;
    psat [2] = 0.0;
    area = 0.02;
    eps = 0.0;
    mass = 1.0; // Since mass = 1, the acceleration should equal the force
    a[0] = 0.0;
    a[1] = 0.0;
    a[2] = 0.0;

    std::cout << "Test 5" << std::endl;
    gal_accsrps(psat, psun, p, au, area, mass, eps, v, a);
    std::cout << std::setprecision( std::numeric_limits< double >::digits10 ) << a[ 0 ] << std::endl;
    std::cout << std::setprecision( std::numeric_limits< double >::digits10 ) << a[ 1 ] << std::endl;
    std::cout << std::setprecision( std::numeric_limits< double >::digits10 ) << a[ 2 ] << std::endl << "\n";

    //Test 6
    //Calculate acceleration due to solar radiation pressure of satellit at 1 AU
    //http://ccar.colorado.edu/asen5050/projects/projects_2001/aponte/Ulysses.htm
    psat[0] = au;
    psat [1] = 0.0;
    psat [2] = 0.0;
    area = 10.59;
    eps = 0.327;
    mass = 370.0; 
    a[0] = 0.0;
    a[1] = 0.0;
    a[2] = 0.0;

    std::cout << "Test 6" << std::endl;
    gal_accsrps(psat, psun, p, au, area, mass, eps, v, a);
    std::cout << std::setprecision( std::numeric_limits< double >::digits10 ) << a[ 0 ] << std::endl;
    std::cout << std::setprecision( std::numeric_limits< double >::digits10 ) << a[ 1 ] << std::endl;
    std::cout << std::setprecision( std::numeric_limits< double >::digits10 ) << a[ 2 ] << std::endl << "\n";


    return 0;
}
