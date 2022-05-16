"""
In this script all functions are combined in a single object.
"""

import numpy as np
import sys
import scipy
from scipy.optimize import fsolve
import matplotlib.pyplot as plt

class LogicleObject:

    def __init__(self, T, trans=None, W=None, A=None, M=None):

        self.T = T
        self.trans = trans

        if W is None:
            W = 0.5
        self.W = W

        if A is None:
            A = -W
        self.A = A

        if M is None:
            M = compute_M(self.T, self.trans, self.W)
        self.M = M