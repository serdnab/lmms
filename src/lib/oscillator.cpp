#ifndef SINGLE_SOURCE_COMPILE

/*
 * oscillator.cpp - implementation of powerful oscillator-class
 *
 * Copyright (c) 2004-2008 Tobias Doerffel <tobydox/at/users.sourceforge.net>
 * 
 * This file is part of Linux MultiMedia Studio - http://lmms.sourceforge.net
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public
 * License as published by the Free Software Foundation; either
 * version 2 of the License, or (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * General Public License for more details.
 *
 * You should have received a copy of the GNU General Public
 * License along with this program (see COPYING); if not, write to the
 * Free Software Foundation, Inc., 51 Franklin Street, Fifth Floor,
 * Boston, MA 02110-1301 USA.
 *
 */


#include "oscillator.h"



oscillator::oscillator( const intModel & _wave_shape_model,
				const intModel & _mod_algo_model,
				const float & _freq,
				const float & _detuning,
				const float & _phase_offset,
				const float & _volume,
			oscillator * _sub_osc ) :
	m_waveShapeModel( _wave_shape_model ),
	m_modulationAlgoModel( _mod_algo_model ),
	m_freq( _freq ),
	m_detuning( _detuning ),
	m_volume( _volume ),
	m_ext_phaseOffset( _phase_offset ),
	m_subOsc( _sub_osc ),
	m_phaseOffset( _phase_offset ),
	m_phase( _phase_offset ),
	m_userWave( NULL )
{
}




void oscillator::update( sampleFrame * _ab, const fpp_t _frames,
							const ch_cnt_t _chnl )
{
	if( m_subOsc != NULL )
	{
		switch( m_modulationAlgoModel.value() )
		{
			case PhaseModulation:
				updatePM( _ab, _frames, _chnl );
				break;
			case AmplitudeModulation:
				updateAM( _ab, _frames, _chnl );
				break;
			case SignalMix:
				updateMix( _ab, _frames, _chnl );
				break;
			case SynchronizedBySubOsc:
				updateSync( _ab, _frames, _chnl );
				break;
			case FrequencyModulation:
				updateFM( _ab, _frames, _chnl );
		}
	}
	else
	{
		updateNoSub( _ab, _frames, _chnl );
	}
}




void oscillator::updateNoSub( sampleFrame * _ab, const fpp_t _frames,
							const ch_cnt_t _chnl )
{
	switch( m_waveShapeModel.value() )
	{
		case SineWave:
		default:
			updateNoSub<SineWave>( _ab, _frames, _chnl );
			break;
		case TriangleWave:
			updateNoSub<TriangleWave>( _ab, _frames, _chnl );
			break;
		case SawWave:
			updateNoSub<SawWave>( _ab, _frames, _chnl );
			break;
		case SquareWave:
			updateNoSub<SquareWave>( _ab, _frames, _chnl );
			break;
		case MoogSawWave:
			updateNoSub<MoogSawWave>( _ab, _frames, _chnl );
			break;
		case ExponentialWave:
			updateNoSub<ExponentialWave>( _ab, _frames, _chnl );
			break;
		case WhiteNoise:
			updateNoSub<WhiteNoise>( _ab, _frames, _chnl );
			break;
		case UserDefinedWave:
			updateNoSub<UserDefinedWave>( _ab, _frames, _chnl );
			break;
	}
}




void oscillator::updatePM( sampleFrame * _ab, const fpp_t _frames,
							const ch_cnt_t _chnl )
{
	switch( m_waveShapeModel.value() )
	{
		case SineWave:
		default:
			updatePM<SineWave>( _ab, _frames, _chnl );
			break;
		case TriangleWave:
			updatePM<TriangleWave>( _ab, _frames, _chnl );
			break;
		case SawWave:
			updatePM<SawWave>( _ab, _frames, _chnl );
			break;
		case SquareWave:
			updatePM<SquareWave>( _ab, _frames, _chnl );
			break;
		case MoogSawWave:
			updatePM<MoogSawWave>( _ab, _frames, _chnl );
			break;
		case ExponentialWave:
			updatePM<ExponentialWave>( _ab, _frames, _chnl );
			break;
		case WhiteNoise:
			updatePM<WhiteNoise>( _ab, _frames, _chnl );
			break;
		case UserDefinedWave:
			updatePM<UserDefinedWave>( _ab, _frames, _chnl );
			break;
	}
}




void oscillator::updateAM( sampleFrame * _ab, const fpp_t _frames,
							const ch_cnt_t _chnl )
{
	switch( m_waveShapeModel.value() )
	{
		case SineWave:
		default:
			updateAM<SineWave>( _ab, _frames, _chnl );
			break;
		case TriangleWave:
			updateAM<TriangleWave>( _ab, _frames, _chnl );
			break;
		case SawWave:
			updateAM<SawWave>( _ab, _frames, _chnl );
			break;
		case SquareWave:
			updateAM<SquareWave>( _ab, _frames, _chnl );
			break;
		case MoogSawWave:
			updateAM<MoogSawWave>( _ab, _frames, _chnl );
			break;
		case ExponentialWave:
			updateAM<ExponentialWave>( _ab, _frames, _chnl );
			break;
		case WhiteNoise:
			updateAM<WhiteNoise>( _ab, _frames, _chnl );
			break;
		case UserDefinedWave:
			updateAM<UserDefinedWave>( _ab, _frames, _chnl );
			break;
	}
}




void oscillator::updateMix( sampleFrame * _ab, const fpp_t _frames,
							const ch_cnt_t _chnl )
{
	switch( m_waveShapeModel.value() )
	{
		case SineWave:
		default:
			updateMix<SineWave>( _ab, _frames, _chnl );
			break;
		case TriangleWave:
			updateMix<TriangleWave>( _ab, _frames, _chnl );
			break;
		case SawWave:
			updateMix<SawWave>( _ab, _frames, _chnl );
			break;
		case SquareWave:
			updateMix<SquareWave>( _ab, _frames, _chnl );
			break;
		case MoogSawWave:
			updateMix<MoogSawWave>( _ab, _frames, _chnl );
			break;
		case ExponentialWave:
			updateMix<ExponentialWave>( _ab, _frames, _chnl );
			break;
		case WhiteNoise:
			updateMix<WhiteNoise>( _ab, _frames, _chnl );
			break;
		case UserDefinedWave:
			updateMix<UserDefinedWave>( _ab, _frames, _chnl );
			break;
	}
}




void oscillator::updateSync( sampleFrame * _ab, const fpp_t _frames,
							const ch_cnt_t _chnl )
{
	switch( m_waveShapeModel.value() )
	{
		case SineWave:
		default:
			updateSync<SineWave>( _ab, _frames, _chnl );
			break;
		case TriangleWave:
			updateSync<TriangleWave>( _ab, _frames, _chnl );
			break;
		case SawWave:
			updateSync<SawWave>( _ab, _frames, _chnl );
			break;
		case SquareWave:
			updateSync<SquareWave>( _ab, _frames, _chnl );
			break;
		case MoogSawWave:
			updateSync<MoogSawWave>( _ab, _frames, _chnl );
			break;
		case ExponentialWave:
			updateSync<ExponentialWave>( _ab, _frames, _chnl );
			break;
		case WhiteNoise:
			updateSync<WhiteNoise>( _ab, _frames, _chnl );
			break;
		case UserDefinedWave:
			updateSync<UserDefinedWave>( _ab, _frames, _chnl );
			break;
	}
}




void oscillator::updateFM( sampleFrame * _ab, const fpp_t _frames,
							const ch_cnt_t _chnl )
{
	switch( m_waveShapeModel.value() )
	{
		case SineWave:
		default:
			updateFM<SineWave>( _ab, _frames, _chnl );
			break;
		case TriangleWave:
			updateFM<TriangleWave>( _ab, _frames, _chnl );
			break;
		case SawWave:
			updateFM<SawWave>( _ab, _frames, _chnl );
			break;
		case SquareWave:
			updateFM<SquareWave>( _ab, _frames, _chnl );
			break;
		case MoogSawWave:
			updateFM<MoogSawWave>( _ab, _frames, _chnl );
			break;
		case ExponentialWave:
			updateFM<ExponentialWave>( _ab, _frames, _chnl );
			break;
		case WhiteNoise:
			updateFM<WhiteNoise>( _ab, _frames, _chnl );
			break;
		case UserDefinedWave:
			updateFM<UserDefinedWave>( _ab, _frames, _chnl );
			break;
	}
}




// should be called every time phase-offset is changed...
inline void oscillator::recalcPhase( void )
{
	if( m_phaseOffset != m_ext_phaseOffset )
	{
		m_phase -= m_phaseOffset;
		m_phaseOffset = m_ext_phaseOffset;
		m_phase += m_phaseOffset;
	}
	m_phase = fraction( m_phase );
}




inline bool oscillator::syncOk( float _osc_coeff )
{
	const float v1 = m_phase;
	m_phase += _osc_coeff;
	// check whether m_phase is in next period
	return( floorf( m_phase ) > floorf( v1 ) );
}




float oscillator::syncInit( sampleFrame * _ab, const fpp_t _frames,
						const ch_cnt_t _chnl )
{
	if( m_subOsc != NULL )
	{
		m_subOsc->update( _ab, _frames, _chnl );
	}
	recalcPhase();
	return( m_freq * m_detuning );
}




// if we have no sub-osc, we can't do any modulation... just get our samples
template<oscillator::WaveShapes W>
void oscillator::updateNoSub( sampleFrame * _ab, const fpp_t _frames,
							const ch_cnt_t _chnl )
{
	recalcPhase();
	const float osc_coeff = m_freq * m_detuning;

	for( fpp_t frame = 0; frame < _frames; ++frame )
	{
		_ab[frame][_chnl] = getSample<W>( m_phase ) * m_volume;
		m_phase += osc_coeff;
	}
}




// do pm by using sub-osc as modulator
template<oscillator::WaveShapes W>
void oscillator::updatePM( sampleFrame * _ab, const fpp_t _frames,
							const ch_cnt_t _chnl )
{
	m_subOsc->update( _ab, _frames, _chnl );
	recalcPhase();
	const float osc_coeff = m_freq * m_detuning;

	for( fpp_t frame = 0; frame < _frames; ++frame )
	{
		_ab[frame][_chnl] = getSample<W>( m_phase + _ab[frame][_chnl] )
							* m_volume;
		m_phase += osc_coeff;
	}
}




// do am by using sub-osc as modulator
template<oscillator::WaveShapes W>
void oscillator::updateAM( sampleFrame * _ab, const fpp_t _frames,
							const ch_cnt_t _chnl )
{
	m_subOsc->update( _ab, _frames, _chnl );
	recalcPhase();
	const float osc_coeff = m_freq * m_detuning;

	for( fpp_t frame = 0; frame < _frames; ++frame )
	{
		_ab[frame][_chnl] *= getSample<W>( m_phase ) * m_volume;
		m_phase += osc_coeff;
	}
}




// do mix by using sub-osc as mix-sample
template<oscillator::WaveShapes W>
void oscillator::updateMix( sampleFrame * _ab, const fpp_t _frames,
							const ch_cnt_t _chnl )
{
	m_subOsc->update( _ab, _frames, _chnl );
	recalcPhase();
	const float osc_coeff = m_freq * m_detuning;

	for( fpp_t frame = 0; frame < _frames; ++frame )
	{
		_ab[frame][_chnl] += getSample<W>( m_phase ) * m_volume;
		m_phase += osc_coeff;
	}
}




// sync with sub-osc (every time sub-osc starts new period, we also start new
// period)
template<oscillator::WaveShapes W>
void oscillator::updateSync( sampleFrame * _ab, const fpp_t _frames,
							const ch_cnt_t _chnl )
{
	const float sub_osc_coeff = m_subOsc->syncInit( _ab, _frames, _chnl );
	recalcPhase();
	const float osc_coeff = m_freq * m_detuning;

	for( fpp_t frame = 0; frame < _frames ; ++frame )
	{
		if( m_subOsc->syncOk( sub_osc_coeff ) )
		{
			m_phase = m_phaseOffset;
		}
		_ab[frame][_chnl] = getSample<W>( m_phase ) * m_volume;
		m_phase += osc_coeff;
	}
}




// do fm by using sub-osc as modulator
template<oscillator::WaveShapes W>
void oscillator::updateFM( sampleFrame * _ab, const fpp_t _frames,
							const ch_cnt_t _chnl )
{
	m_subOsc->update( _ab, _frames, _chnl );
	recalcPhase();
	const float osc_coeff = m_freq * m_detuning;

	for( fpp_t frame = 0; frame < _frames; ++frame )
	{
		m_phase += _ab[frame][_chnl];
		_ab[frame][_chnl] = getSample<W>( m_phase ) * m_volume;
		m_phase += osc_coeff;
	}
}




template<>
inline sample_t oscillator::getSample<oscillator::SineWave>(
							const float _sample )
{
	return( sinSample( _sample ) );
}




template<>
inline sample_t oscillator::getSample<oscillator::TriangleWave>(
							const float _sample )
{
	return( triangleSample( _sample ) );
}




template<>
inline sample_t oscillator::getSample<oscillator::SawWave>(
							const float _sample )
{
	return( sawSample( _sample ) );
}




template<>
inline sample_t oscillator::getSample<oscillator::SquareWave>(
							const float _sample )
{
	return( squareSample( _sample ) );
}




template<>
inline sample_t oscillator::getSample<oscillator::MoogSawWave>(
							const float _sample )
{
	return( moogSawSample( _sample ) );
}




template<>
inline sample_t oscillator::getSample<oscillator::ExponentialWave>(
							const float _sample )
{
	return( expSample( _sample ) );
}




template<>
inline sample_t oscillator::getSample<oscillator::WhiteNoise>(
							const float _sample )
{
	return( noiseSample( _sample ) );
}




template<>
inline sample_t oscillator::getSample<oscillator::UserDefinedWave>(
							const float _sample )
{
	return( userWaveSample( _sample ) );
}




#endif
