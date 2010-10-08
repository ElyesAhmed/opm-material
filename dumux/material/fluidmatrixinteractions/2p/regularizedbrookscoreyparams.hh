// $Id$
/*****************************************************************************
 *   Copyright (C) 2008 by Andreas Lauser, Bernd Flemisch                    *
 *   Institute of Hydraulic Engineering                                      *
 *   University of Stuttgart, Germany                                        *
 *   email: <givenname>.<name>@iws.uni-stuttgart.de                          *
 *                                                                           *
 *   This program is free software; you can redistribute it and/or modify    *
 *   it under the terms of the GNU General Public License as published by    *
 *   the Free Software Foundation; either version 2 of the License, or       *
 *   (at your option) any later version, as long as this copyright notice    *
 *   is included in its original form.                                       *
 *                                                                           *
 *   This program is distributed WITHOUT ANY WARRANTY.                       *
 *****************************************************************************/
/*!
 * \file
 *
 * \brief Specification of the params API for the Brooks-Corey
 *        capillary pressure model.
 */
#ifndef DUMUX_REGULARIZED_BROOKS_COREY_PARAMS_HH
#define DUMUX_REGULARIZED_BROOKS_COREY_PARAMS_HH

#include "brookscoreyparams.hh"

namespace Dumux
{
/*!
 * \brief A reference implementation of the params class for the
 *        regularized Brooks-Corey Sw-pC relation.
 */
template <class ScalarT>
class RegularizedBrooksCoreyParams : public Dumux::BrooksCoreyParams<ScalarT>
{
    typedef Dumux::BrooksCoreyParams<ScalarT> BrooksCoreyParams;

public:
    typedef ScalarT Scalar;

    RegularizedBrooksCoreyParams()
        : BrooksCoreyParams()
    {
    }

    RegularizedBrooksCoreyParams(Scalar pe, Scalar alpha)
        : BrooksCoreyParams(pe, alpha)
    {
    }

    /*!
     * \brief Threshold saturation below which the capillary pressure
     *        is regularized.
     *
     * This is just 1%. If you need a different value, overload this
     * class.
     */
    Scalar thresholdSw() const
    {
        // Some problems are very sensitive to this value
        // (e.g. makeing it smaller might result in negative
        // pressures), if you change it here, you will almost
        // certainly break someone's code!
        //
        // If you want to use a different regularization threshold,
        // overload this class and supply the new class as second
        // template parameter for the RegularizedVanGenuchten law!
        return /* PLEASE DO _NOT_ */ 1e-2; /* CHANGE THIS VALUE. READ
                                            * COMMENT ABOVE! */
    }

};
}; // namespace Dumux

#endif