////////////////////////////////////////////////////////////////////////
// ShaderProgram.inl
// Copyright (C) 2011  Olivier Guittonneau openmengine@gmail.com
////////////////////////////////////////////////////////////////////////

template <typename T>
void ShaderProgram::sendUniform(const std::string &name, T &data)
{
    data.sendAsUniform(*this, name);
}
