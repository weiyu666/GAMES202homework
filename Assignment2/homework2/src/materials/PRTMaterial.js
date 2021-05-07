class PRTMaterial extends Material {

    constructor(color, specular, light, translate, scale, vertexShader, fragmentShader) {
        let lightIntensity = light.mat.GetIntensity();

        super({                    
            'uPrecomputeLR': { type: 'updatedInRealTime', value: null },   
            'uPrecomputeLG': { type: 'updatedInRealTime', value: null },   
            'uPrecomputeLB': { type: 'updatedInRealTime', value: null },   
            'uSampler': { type: 'texture', value: color },
        }, ['aPrecomputeLT'], vertexShader, fragmentShader, null);
    }
}

async function buildPRTMaterial(color, specular, light, translate, scale, vertexPath, fragmentPath) {
    let vertexShader = await getShaderString(vertexPath);
    let fragmentShader = await getShaderString(fragmentPath);

    return new PRTMaterial(color, specular, light, translate, scale, vertexShader, fragmentShader);

}