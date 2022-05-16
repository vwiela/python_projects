"""AMICI-generated module for model Spoegler_conversionReaction"""

import amici

# Ensure we are binary-compatible, see #556
if '0.11.25' != amici.__version__:
    raise RuntimeError('Cannot use model Spoegler_conversionReaction, generated with AMICI '
                       'version 0.11.25, together with AMICI version'
                       f' {amici.__version__} which is present in your '
                       'PYTHONPATH. Install the AMICI package matching the '
                       'model version or regenerate the model with the AMICI '
                       'currently in your path.')

from Spoegler_conversionReaction._Spoegler_conversionReaction import *

__version__ = '0.1.0'
