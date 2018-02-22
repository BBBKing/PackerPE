#pragma once

#include "includes.h"
#include "isections_packer.h"

class SectionsPacker:
  public ISectionsPacker
{
public:
  SectionsPacker(std::shared_ptr<PeLib::PeFile>& srcPEFile):
    ISectionsPacker(srcPEFile)
  {}
  SectionsArr ProcessExecutable(
    const std::vector<uint8_t>& sourceFileBuff
    , const std::vector<RequiredDataBlock> additionalSizeRequest);
  Expected<ErrorCode> IsReady() const { return ErrorCode::ERROR_SUCC; }
  std::vector<RequiredDataBlock> GetRequiredDataBlocks() const { return std::vector<RequiredDataBlock>(); }
};