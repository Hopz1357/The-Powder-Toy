#include "simulation/ElementCommon.h"

void Element::Element_HL()
{
	Identifier = "DEFAULT_PT_HL";
	Name = "H-l";
	Colour = 0x4B6CFF_rgb;
	MenuVisible = 0;
	MenuSection = SC_ATOM;
	Enabled = 1;

	Advection = 0.6f;
	AirDrag = 0.01f * CFDS;
	AirLoss = 0.98f;
	Loss = 0.95f;
	Collision = 0.0f;
	Gravity = 0.1f;
	Diffusion = 0.00f;
	HotAir = 0.000f * CFDS;
	Falldown = 2;

	Flammable = 0;
	Explosive = 0;
	Meltable = 0;
	Hardness = 0;

	Weight = 1;

	DefaultProperties.temp = R_TEMP - 277.0f + 273.15f;
	DefaultProperties.state = 1;
	HeatConduct = 251;
	Description = "Liquid Hydrogen.";

	Properties = TYPE_LIQUID;

	LowPressure = IPL;
	LowPressureTransition = NT;
	HighPressure = IPH;
	HighPressureTransition = NT;
	LowTemperature = 14.01f;
	LowTemperatureTransition = PT_HS;
	HighTemperature = 20.28f;
	HighTemperatureTransition = PT_H2;
}
