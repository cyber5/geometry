#ifndef BOOST_GEOMETRY_PROJECTIONS_PUTP5_HPP
#define BOOST_GEOMETRY_PROJECTIONS_PUTP5_HPP

// Boost.Geometry - extensions-gis-projections (based on PROJ4)
// This file is automatically generated. DO NOT EDIT.

// Copyright (c) 2008-2015 Barend Gehrels, Amsterdam, the Netherlands.

// Use, modification and distribution is subject to the Boost Software License,
// Version 1.0. (See accompanying file LICENSE_1_0.txt or copy at
// http://www.boost.org/LICENSE_1_0.txt)

// This file is converted from PROJ4, http://trac.osgeo.org/proj
// PROJ4 is originally written by Gerald Evenden (then of the USGS)
// PROJ4 is maintained by Frank Warmerdam
// PROJ4 is converted to Boost.Geometry by Barend Gehrels

// Last updated version of proj: 4.9.1

// Original copyright notice:
 
// Permission is hereby granted, free of charge, to any person obtaining a
// copy of this software and associated documentation files (the "Software"),
// to deal in the Software without restriction, including without limitation
// the rights to use, copy, modify, merge, publish, distribute, sublicense,
// and/or sell copies of the Software, and to permit persons to whom the
// Software is furnished to do so, subject to the following conditions:

// The above copyright notice and this permission notice shall be included
// in all copies or substantial portions of the Software.

// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS
// OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL
// THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
// FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER
// DEALINGS IN THE SOFTWARE.


#include <boost/core/ignore_unused.hpp>

#include <boost/geometry/extensions/gis/projections/impl/base_static.hpp>
#include <boost/geometry/extensions/gis/projections/impl/base_dynamic.hpp>
#include <boost/geometry/extensions/gis/projections/impl/projects.hpp>
#include <boost/geometry/extensions/gis/projections/impl/factory_entry.hpp>

namespace boost { namespace geometry { namespace projections
{
    #ifndef DOXYGEN_NO_DETAIL
    namespace detail { namespace putp5{
            static const double C = 1.01346;
            static const double D = 1.2158542;

            struct par_putp5
            {
                double    A, B;
            };

            // template class, using CRTP to implement forward/inverse
            template <typename Geographic, typename Cartesian, typename Parameters>
            struct base_putp5_spheroid : public base_t_fi<base_putp5_spheroid<Geographic, Cartesian, Parameters>,
                     Geographic, Cartesian, Parameters>
            {

                 typedef double geographic_type;
                 typedef double cartesian_type;

                par_putp5 m_proj_parm;

                inline base_putp5_spheroid(const Parameters& par)
                    : base_t_fi<base_putp5_spheroid<Geographic, Cartesian, Parameters>,
                     Geographic, Cartesian, Parameters>(*this, par) {}

                inline void fwd(geographic_type& lp_lon, geographic_type& lp_lat, cartesian_type& xy_x, cartesian_type& xy_y) const
                {
                    xy_x = C * lp_lon * (this->m_proj_parm.A - this->m_proj_parm.B * sqrt(1. + D * lp_lat * lp_lat));
                    xy_y = C * lp_lat;
                }

                inline void inv(cartesian_type& xy_x, cartesian_type& xy_y, geographic_type& lp_lon, geographic_type& lp_lat) const
                {
                    lp_lat = xy_y / C;
                    lp_lon = xy_x / (C * (this->m_proj_parm.A - this->m_proj_parm.B * sqrt(1. + D * lp_lat * lp_lat)));
                }
            };

            template <typename Parameters>
            void setup(Parameters& par, par_putp5& proj_parm) 
            {
                boost::ignore_unused(proj_parm);
                par.es = 0.;
                // par.inv = s_inverse;
                // par.fwd = s_forward;
            }


            // Putnins P5
            template <typename Parameters>
            void setup_putp5(Parameters& par, par_putp5& proj_parm)
            {
                proj_parm.A = 2.;
                proj_parm.B = 1.;
                setup(par, proj_parm);
            }

            // Putnins P5'
            template <typename Parameters>
            void setup_putp5p(Parameters& par, par_putp5& proj_parm)
            {
                proj_parm.A = 1.5;
                proj_parm.B = 0.5;
                setup(par, proj_parm);
            }

        }} // namespace detail::putp5
    #endif // doxygen

    /*!
        \brief Putnins P5 projection
        \ingroup projections
        \tparam Geographic latlong point type
        \tparam Cartesian xy point type
        \tparam Parameters parameter type
        \par Projection characteristics
         - Pseudocylindrical
         - Spheroid
        \par Example
        \image html ex_putp5.gif
    */
    template <typename Geographic, typename Cartesian, typename Parameters = parameters>
    struct putp5_spheroid : public detail::putp5::base_putp5_spheroid<Geographic, Cartesian, Parameters>
    {
        inline putp5_spheroid(const Parameters& par) : detail::putp5::base_putp5_spheroid<Geographic, Cartesian, Parameters>(par)
        {
            detail::putp5::setup_putp5(this->m_par, this->m_proj_parm);
        }
    };

    /*!
        \brief Putnins P5' projection
        \ingroup projections
        \tparam Geographic latlong point type
        \tparam Cartesian xy point type
        \tparam Parameters parameter type
        \par Projection characteristics
         - Pseudocylindrical
         - Spheroid
        \par Example
        \image html ex_putp5p.gif
    */
    template <typename Geographic, typename Cartesian, typename Parameters = parameters>
    struct putp5p_spheroid : public detail::putp5::base_putp5_spheroid<Geographic, Cartesian, Parameters>
    {
        inline putp5p_spheroid(const Parameters& par) : detail::putp5::base_putp5_spheroid<Geographic, Cartesian, Parameters>(par)
        {
            detail::putp5::setup_putp5p(this->m_par, this->m_proj_parm);
        }
    };

    #ifndef DOXYGEN_NO_DETAIL
    namespace detail
    {

        // Factory entry(s)
        template <typename Geographic, typename Cartesian, typename Parameters>
        class putp5_entry : public detail::factory_entry<Geographic, Cartesian, Parameters>
        {
            public :
                virtual projection<Geographic, Cartesian>* create_new(const Parameters& par) const
                {
                    return new base_v_fi<putp5_spheroid<Geographic, Cartesian, Parameters>, Geographic, Cartesian, Parameters>(par);
                }
        };

        template <typename Geographic, typename Cartesian, typename Parameters>
        class putp5p_entry : public detail::factory_entry<Geographic, Cartesian, Parameters>
        {
            public :
                virtual projection<Geographic, Cartesian>* create_new(const Parameters& par) const
                {
                    return new base_v_fi<putp5p_spheroid<Geographic, Cartesian, Parameters>, Geographic, Cartesian, Parameters>(par);
                }
        };

        template <typename Geographic, typename Cartesian, typename Parameters>
        inline void putp5_init(detail::base_factory<Geographic, Cartesian, Parameters>& factory)
        {
            factory.add_to_factory("putp5", new putp5_entry<Geographic, Cartesian, Parameters>);
            factory.add_to_factory("putp5p", new putp5p_entry<Geographic, Cartesian, Parameters>);
        }

    } // namespace detail
    #endif // doxygen

}}} // namespace boost::geometry::projections

#endif // BOOST_GEOMETRY_PROJECTIONS_PUTP5_HPP

