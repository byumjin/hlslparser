#ifndef HLSL_TOKENIZER_H
#define HLSL_TOKENIZER_H

namespace M4
{

/** In addition to the values in this enum, all of the ASCII characters are
valid tokens. */
enum HLSLToken
{
    // Built-in types.
	
	HLSLToken_Float = 256,
	HLSLToken_Float1x2,	
	HLSLToken_Float1x3,	
	HLSLToken_Float1x4,	
	HLSLToken_Float2,	
	HLSLToken_Float2x2,	
	HLSLToken_Float2x3,	
	HLSLToken_Float2x4,	
	HLSLToken_Float3,	
	HLSLToken_Float3x2,	
	HLSLToken_Float3x3,	
	HLSLToken_Float3x4,	
	HLSLToken_Float4,	
	HLSLToken_Float4x2,	
	HLSLToken_Float4x3,	
	HLSLToken_Float4x4,	

	HLSLToken_Half,		//272
	HLSLToken_Half1x2,	//273
	HLSLToken_Half1x3,	//274
	HLSLToken_Half1x4,	//275
	HLSLToken_Half2,	//276
	HLSLToken_Half2x2,	//278
	HLSLToken_Half2x3,	//279
	HLSLToken_Half2x4,	//280
	HLSLToken_Half3,	//281
	HLSLToken_Half3x2,	//282
	HLSLToken_Half3x3,	//283
	HLSLToken_Half3x4,	//284
	HLSLToken_Half4,	//285
	HLSLToken_Half4x2,	//286
	HLSLToken_Half4x3,	//287
	HLSLToken_Half4x4,	//288
   
	HLSLToken_Bool,		//288
	HLSLToken_Bool1x2,	
	HLSLToken_Bool1x3,	
	HLSLToken_Bool1x4,	
	HLSLToken_Bool2,	
	HLSLToken_Bool2x2,	
	HLSLToken_Bool2x3,	
	HLSLToken_Bool2x4,	
	HLSLToken_Bool3,	
	HLSLToken_Bool3x2,	
	HLSLToken_Bool3x3,	
	HLSLToken_Bool3x4,	
	HLSLToken_Bool4,	
	HLSLToken_Bool4x2,	
	HLSLToken_Bool4x3,	
	HLSLToken_Bool4x4,	

	HLSLToken_Int,		//304
	HLSLToken_Int1x2,	
	HLSLToken_Int1x3,	
	HLSLToken_Int1x4,	
	HLSLToken_Int2,		
	HLSLToken_Int2x2,	
	HLSLToken_Int2x3,	
	HLSLToken_Int2x4,	
	HLSLToken_Int3,		
	HLSLToken_Int3x2,	
	HLSLToken_Int3x3,	
	HLSLToken_Int3x4,	
	HLSLToken_Int4,		
	HLSLToken_Int4x2,	
	HLSLToken_Int4x3,	
	HLSLToken_Int4x4,	

	HLSLToken_Uint,		//320
	HLSLToken_Uint1x2,	
	HLSLToken_Uint1x3,	
	HLSLToken_Uint1x4,	
	HLSLToken_Uint2,	
	HLSLToken_Uint2x2,	
	HLSLToken_Uint2x3,	
	HLSLToken_Uint2x4,	
	HLSLToken_Uint3,	
	HLSLToken_Uint3x2,	
	HLSLToken_Uint3x3,	
	HLSLToken_Uint3x4,	
	HLSLToken_Uint4,	
	HLSLToken_Uint4x2,	
	HLSLToken_Uint4x3,	
	HLSLToken_Uint4x4,	

    HLSLToken_Texture,	//336
    HLSLToken_Sampler,
    HLSLToken_Sampler2D,
    HLSLToken_Sampler3D,
    HLSLToken_SamplerCube,
    HLSLToken_Sampler2DShadow,   
    HLSLToken_Sampler2DMS,
    HLSLToken_Sampler2DArray,

    // Reserved words.
    HLSLToken_If,
    HLSLToken_Else,
    HLSLToken_For,
    HLSLToken_While,
    HLSLToken_Break,
    HLSLToken_True,
    HLSLToken_False,
    HLSLToken_Void,				
    HLSLToken_Struct,
    HLSLToken_CBuffer,
    HLSLToken_TBuffer,
    HLSLToken_Register,
    HLSLToken_Return,
    HLSLToken_Continue,
    HLSLToken_Discard,
    HLSLToken_Const,
    HLSLToken_Static,
    HLSLToken_Inline,	

	// Preprocessors
	HLSLToken_P_Define,
	HLSLToken_P_Elif,
	HLSLToken_P_Else,
	HLSLToken_P_Endif,
	HLSLToken_P_Error,
	HLSLToken_P_If,
	HLSLToken_P_IfDef,
	HLSLToken_P_IfnDef,
	HLSLToken_P_Include,
	HLSLToken_P_Line,
	HLSLToken_P_Pragma,
	HLSLToken_P_Undef,

    // Input modifiers.
    HLSLToken_Uniform,
    HLSLToken_In,
    HLSLToken_Out,
    HLSLToken_InOut,

    // Effect keywords.
    HLSLToken_SamplerState,
    HLSLToken_Technique,
    HLSLToken_Pass,

    // Multi-character symbols.
    HLSLToken_LessEqual,
    HLSLToken_GreaterEqual,
    HLSLToken_EqualEqual,
    HLSLToken_NotEqual,
    HLSLToken_PlusPlus,
    HLSLToken_MinusMinus,
    HLSLToken_PlusEqual,
    HLSLToken_MinusEqual,
    HLSLToken_TimesEqual,
    HLSLToken_DivideEqual,
    HLSLToken_AndAnd,       // &&
    HLSLToken_BarBar,       // ||

    // Other token types.
    HLSLToken_FloatLiteral,
	HLSLToken_HalfLiteral,
    HLSLToken_IntLiteral,
	HLSLToken_UintLiteral = HLSLToken_IntLiteral,
    HLSLToken_Identifier,

    HLSLToken_EndOfStream,
};

class HLSLTokenizer
{

public:

    /// Maximum string length of an identifier.
    static const int s_maxIdentifier = 255 + 1;

    /** The file name is only used for error reporting. */
    HLSLTokenizer(const char* fileName, const char* buffer, size_t length);

    /** Advances to the next token in the stream. */
    void Next();

    /** Returns the current token in the stream. */
    int GetToken() const;

    /** Returns the number of the current token. */
    float GetFloat() const;
    int   GetInt() const;

    /** Returns the identifier for the current token. */
    const char* GetIdentifier() const;

    /** Returns the line number where the current token began. */
    int GetLineNumber() const;

    /** Returns the file name where the current token began. */
    const char* GetFileName() const;

    /** Gets a human readable text description of the current token. */
    void GetTokenName(char buffer[s_maxIdentifier]) const;

    /** Reports an error using printf style formatting. The current line number
    is included. Only the first error reported will be output. */
    void Error(const char* format, ...);

    /** Gets a human readable text description of the specified token. */
    static void GetTokenName(int token, char buffer[s_maxIdentifier]);

private:

    bool SkipWhitespace();
    bool SkipComment();
	bool SkipPragmaDirective();
    bool ScanNumber();
    bool ScanLineDirective();

private:

    const char*         m_fileName;
    const char*         m_buffer;
    const char*         m_bufferEnd;
    int                 m_lineNumber;
    bool                m_error;

    int                 m_token;
    float               m_fValue;
    int                 m_iValue;
    char                m_identifier[s_maxIdentifier];
    char                m_lineDirectiveFileName[s_maxIdentifier];
    int                 m_tokenLineNumber;

};

}

#endif