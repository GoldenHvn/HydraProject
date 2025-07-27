#ifndef HYDRA_TERRAINSHADER_H
#define HYDRA_TERRAINSHADER_H

namespace hydra {

// Simple HLSL terrain shader targeting DirectX 12
static const char g_terrainShader[] = R"(
cbuffer TerrainCB : register(b0)
{
    float4x4 World;
    float4x4 ViewProj;
    float4   EyePos;
    float4   Params; // x: tex scale, y: fog offset
};

struct VSInput
{
    float3 pos : POSITION;
    float3 nor : NORMAL;
    float2 uv  : TEXCOORD0;
};

struct PSInput
{
    float4 pos  : SV_POSITION;
    float2 uv0  : TEXCOORD0;
    float2 uv1  : TEXCOORD1;
    float  fog  : FOG;
};

PSInput VSMain(VSInput vin)
{
    PSInput vout;
    float4 wpos = mul(float4(vin.pos, 1.0f), World);
    float4 clip = mul(wpos, ViewProj);
    vout.pos = clip;

    float invZ = 1.0f / clip.w;
    float2 proj = clip.xy * invZ + Params.yy;

    float3 n = normalize(mul(vin.nor, (float3x3)World));
    float2 env = proj + n.xy * Params.x;
    vout.uv0 = env;
    vout.fog = invZ;

    float3 toEye = normalize(EyePos.xyz - wpos.xyz);
    float3 r = reflect(-toEye, n);
    vout.uv1 = r.xy * 0.5f + 0.5f;
    return vout;
}

float4 PSMain(PSInput pin) : SV_TARGET
{
    // Placeholder pixel shader samples would go here
    return float4(pin.uv1, 0.0f, 1.0f);
}
)";

} // namespace hydra

#endif // HYDRA_TERRAINSHADER_H
