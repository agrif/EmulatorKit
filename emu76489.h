#ifndef _EMU76489_H_
#define _EMU76489_H_
#include "stdint.h"

typedef struct __SNG {

  int32_t out;

  uint32_t clk, rate, base_incr, quality;

  uint32_t count[3];
  uint32_t volume[3];
  uint32_t freq[3];
  uint32_t edge[3];
  uint32_t mute[3];

  uint32_t noise_seed;
  uint32_t noise_count;
  uint32_t noise_freq;
  uint32_t noise_volume;
  uint32_t noise_mode;
  uint32_t noise_fref;

 uint32_t base_count;

/* rate converter */
  uint32_t realstep;
  uint32_t sngtime;
  uint32_t sngstep;

  uint32_t adr;
  uint8_t ready;
  int16_t ch_out[4];

} SNG;
	
SNG *SNG_new(uint32_t clk, uint32_t rate);
void SNG_delete(SNG *);
void SNG_reset(SNG *);
void SNG_set_rate(SNG *,uint32_t rate);
void SNG_set_quality(SNG *,uint32_t q);
void SNG_writeIO(SNG *SNG, uint32_t val);
uint8_t SNG_readReady(SNG *SNG);
int16_t SNG_calc(SNG *);

#endif
