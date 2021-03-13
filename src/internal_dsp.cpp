/*
    Real time guitar amplifier simulation
    Copyright (C) 2021  Nathaniel D'Rozario

    This program is free software; you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation; either version 2 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License along
    with this program; if not, write to the Free Software Foundation, Inc.,
    51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA.
*/
#include <internal_dsp.hpp>
#include <algorithm>
#include <cmath>

void guitar_amp::dsp::hardclip_minmax(const float *input, float *transform, float gain, float threshold, ma_uint32 frameCount) {
    for (ma_uint32 i = 0; i < frameCount; i++) {
        if (input[i] > 0) {
            transform[i] = std::min(input[i]*gain, threshold);
        } else {
            transform[i] = std::max(input[i]*gain, -threshold);
        }
    }
}

float guitar_amp::dsp::f32_to_dbfs(float x) {
    return 20.0f * log10 ( fabsf(x) );
}

float guitar_amp::dsp::dbfs_to_f32(float x) {
    return powf(10, x / 20.0f);
}