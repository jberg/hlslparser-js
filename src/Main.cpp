#include "../hlslparser/src/GLSLGenerator.h"
#include "../hlslparser/src/HLSLParser.h"
#include "../hlslparser/src/HLSLTree.h"

extern "C" {

    const char* parseHLSL(char* source, char* entryName, char* type)
    {
        using namespace M4;

        const char* fileName = "filename.hlsl";

        // fragment shader by default
        GLSLGenerator::Target target = GLSLGenerator::Target_FragmentShader;
        if (String_Equal(type, "vs")) {
            target = GLSLGenerator::Target_VertexShader;
        }

        // Parse input file
        Allocator allocator;
        HLSLParser parser(&allocator, fileName, source, strlen(source));
        HLSLTree tree(&allocator);
        if (!parser.Parse(&tree))
        {
            const char* ret = "parsing failed";
            return ret;
        }

        // Generate output
        GLSLGenerator generator;
        if (!generator.Generate(&tree, target, GLSLGenerator::Version_100_ES, entryName)) {
            const char* ret = "code generation failed";
            return ret;
        }

        const char *result = generator.GetResult();

        return result;
    }
}
