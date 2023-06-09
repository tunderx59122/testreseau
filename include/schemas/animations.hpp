// automatically generated by the FlatBuffers compiler, do not modify


#ifndef FLATBUFFERS_GENERATED_ANIMATIONS_H_
#define FLATBUFFERS_GENERATED_ANIMATIONS_H_

#include "flatbuffers/flatbuffers.h"

struct AnimationRoot;
struct AnimationRootBuilder;

struct Set;
struct SetBuilder;

struct Animation;
struct AnimationBuilder;

struct Frame;
struct FrameBuilder;

struct AnimationRoot FLATBUFFERS_FINAL_CLASS : private flatbuffers::Table {
  typedef AnimationRootBuilder Builder;
  enum FlatBuffersVTableOffset FLATBUFFERS_VTABLE_UNDERLYING_TYPE {
    VT_ANIMATIONS = 4,
    VT_SPECIALS = 6
  };
  const flatbuffers::Vector<flatbuffers::Offset<Animation>> *animations() const {
    return GetPointer<const flatbuffers::Vector<flatbuffers::Offset<Animation>> *>(VT_ANIMATIONS);
  }
  const flatbuffers::Vector<flatbuffers::Offset<Set>> *specials() const {
    return GetPointer<const flatbuffers::Vector<flatbuffers::Offset<Set>> *>(VT_SPECIALS);
  }
  bool Verify(flatbuffers::Verifier &verifier) const {
    return VerifyTableStart(verifier) &&
           VerifyOffset(verifier, VT_ANIMATIONS) &&
           verifier.VerifyVector(animations()) &&
           verifier.VerifyVectorOfTables(animations()) &&
           VerifyOffset(verifier, VT_SPECIALS) &&
           verifier.VerifyVector(specials()) &&
           verifier.VerifyVectorOfTables(specials()) &&
           verifier.EndTable();
  }
};

struct AnimationRootBuilder {
  typedef AnimationRoot Table;
  flatbuffers::FlatBufferBuilder &fbb_;
  flatbuffers::uoffset_t start_;
  void add_animations(flatbuffers::Offset<flatbuffers::Vector<flatbuffers::Offset<Animation>>> animations) {
    fbb_.AddOffset(AnimationRoot::VT_ANIMATIONS, animations);
  }
  void add_specials(flatbuffers::Offset<flatbuffers::Vector<flatbuffers::Offset<Set>>> specials) {
    fbb_.AddOffset(AnimationRoot::VT_SPECIALS, specials);
  }
  explicit AnimationRootBuilder(flatbuffers::FlatBufferBuilder &_fbb)
        : fbb_(_fbb) {
    start_ = fbb_.StartTable();
  }
  flatbuffers::Offset<AnimationRoot> Finish() {
    const auto end = fbb_.EndTable(start_);
    auto o = flatbuffers::Offset<AnimationRoot>(end);
    return o;
  }
};

inline flatbuffers::Offset<AnimationRoot> CreateAnimationRoot(
    flatbuffers::FlatBufferBuilder &_fbb,
    flatbuffers::Offset<flatbuffers::Vector<flatbuffers::Offset<Animation>>> animations = 0,
    flatbuffers::Offset<flatbuffers::Vector<flatbuffers::Offset<Set>>> specials = 0) {
  AnimationRootBuilder builder_(_fbb);
  builder_.add_specials(specials);
  builder_.add_animations(animations);
  return builder_.Finish();
}

inline flatbuffers::Offset<AnimationRoot> CreateAnimationRootDirect(
    flatbuffers::FlatBufferBuilder &_fbb,
    const std::vector<flatbuffers::Offset<Animation>> *animations = nullptr,
    const std::vector<flatbuffers::Offset<Set>> *specials = nullptr) {
  auto animations__ = animations ? _fbb.CreateVector<flatbuffers::Offset<Animation>>(*animations) : 0;
  auto specials__ = specials ? _fbb.CreateVector<flatbuffers::Offset<Set>>(*specials) : 0;
  return CreateAnimationRoot(
      _fbb,
      animations__,
      specials__);
}

struct Set FLATBUFFERS_FINAL_CLASS : private flatbuffers::Table {
  typedef SetBuilder Builder;
  enum FlatBuffersVTableOffset FLATBUFFERS_VTABLE_UNDERLYING_TYPE {
    VT_TYPE = 4,
    VT_ANIMATIONS = 6
  };
  const flatbuffers::String *type() const {
    return GetPointer<const flatbuffers::String *>(VT_TYPE);
  }
  const flatbuffers::Vector<flatbuffers::Offset<Animation>> *animations() const {
    return GetPointer<const flatbuffers::Vector<flatbuffers::Offset<Animation>> *>(VT_ANIMATIONS);
  }
  bool Verify(flatbuffers::Verifier &verifier) const {
    return VerifyTableStart(verifier) &&
           VerifyOffset(verifier, VT_TYPE) &&
           verifier.VerifyString(type()) &&
           VerifyOffset(verifier, VT_ANIMATIONS) &&
           verifier.VerifyVector(animations()) &&
           verifier.VerifyVectorOfTables(animations()) &&
           verifier.EndTable();
  }
};

struct SetBuilder {
  typedef Set Table;
  flatbuffers::FlatBufferBuilder &fbb_;
  flatbuffers::uoffset_t start_;
  void add_type(flatbuffers::Offset<flatbuffers::String> type) {
    fbb_.AddOffset(Set::VT_TYPE, type);
  }
  void add_animations(flatbuffers::Offset<flatbuffers::Vector<flatbuffers::Offset<Animation>>> animations) {
    fbb_.AddOffset(Set::VT_ANIMATIONS, animations);
  }
  explicit SetBuilder(flatbuffers::FlatBufferBuilder &_fbb)
        : fbb_(_fbb) {
    start_ = fbb_.StartTable();
  }
  flatbuffers::Offset<Set> Finish() {
    const auto end = fbb_.EndTable(start_);
    auto o = flatbuffers::Offset<Set>(end);
    return o;
  }
};

inline flatbuffers::Offset<Set> CreateSet(
    flatbuffers::FlatBufferBuilder &_fbb,
    flatbuffers::Offset<flatbuffers::String> type = 0,
    flatbuffers::Offset<flatbuffers::Vector<flatbuffers::Offset<Animation>>> animations = 0) {
  SetBuilder builder_(_fbb);
  builder_.add_animations(animations);
  builder_.add_type(type);
  return builder_.Finish();
}

inline flatbuffers::Offset<Set> CreateSetDirect(
    flatbuffers::FlatBufferBuilder &_fbb,
    const char *type = nullptr,
    const std::vector<flatbuffers::Offset<Animation>> *animations = nullptr) {
  auto type__ = type ? _fbb.CreateString(type) : 0;
  auto animations__ = animations ? _fbb.CreateVector<flatbuffers::Offset<Animation>>(*animations) : 0;
  return CreateSet(
      _fbb,
      type__,
      animations__);
}

struct Animation FLATBUFFERS_FINAL_CLASS : private flatbuffers::Table {
  typedef AnimationBuilder Builder;
  enum FlatBuffersVTableOffset FLATBUFFERS_VTABLE_UNDERLYING_TYPE {
    VT_NAME = 4,
    VT_FRAMES = 6
  };
  const flatbuffers::String *name() const {
    return GetPointer<const flatbuffers::String *>(VT_NAME);
  }
  const flatbuffers::Vector<flatbuffers::Offset<Frame>> *frames() const {
    return GetPointer<const flatbuffers::Vector<flatbuffers::Offset<Frame>> *>(VT_FRAMES);
  }
  bool Verify(flatbuffers::Verifier &verifier) const {
    return VerifyTableStart(verifier) &&
           VerifyOffset(verifier, VT_NAME) &&
           verifier.VerifyString(name()) &&
           VerifyOffset(verifier, VT_FRAMES) &&
           verifier.VerifyVector(frames()) &&
           verifier.VerifyVectorOfTables(frames()) &&
           verifier.EndTable();
  }
};

struct AnimationBuilder {
  typedef Animation Table;
  flatbuffers::FlatBufferBuilder &fbb_;
  flatbuffers::uoffset_t start_;
  void add_name(flatbuffers::Offset<flatbuffers::String> name) {
    fbb_.AddOffset(Animation::VT_NAME, name);
  }
  void add_frames(flatbuffers::Offset<flatbuffers::Vector<flatbuffers::Offset<Frame>>> frames) {
    fbb_.AddOffset(Animation::VT_FRAMES, frames);
  }
  explicit AnimationBuilder(flatbuffers::FlatBufferBuilder &_fbb)
        : fbb_(_fbb) {
    start_ = fbb_.StartTable();
  }
  flatbuffers::Offset<Animation> Finish() {
    const auto end = fbb_.EndTable(start_);
    auto o = flatbuffers::Offset<Animation>(end);
    return o;
  }
};

inline flatbuffers::Offset<Animation> CreateAnimation(
    flatbuffers::FlatBufferBuilder &_fbb,
    flatbuffers::Offset<flatbuffers::String> name = 0,
    flatbuffers::Offset<flatbuffers::Vector<flatbuffers::Offset<Frame>>> frames = 0) {
  AnimationBuilder builder_(_fbb);
  builder_.add_frames(frames);
  builder_.add_name(name);
  return builder_.Finish();
}

inline flatbuffers::Offset<Animation> CreateAnimationDirect(
    flatbuffers::FlatBufferBuilder &_fbb,
    const char *name = nullptr,
    const std::vector<flatbuffers::Offset<Frame>> *frames = nullptr) {
  auto name__ = name ? _fbb.CreateString(name) : 0;
  auto frames__ = frames ? _fbb.CreateVector<flatbuffers::Offset<Frame>>(*frames) : 0;
  return CreateAnimation(
      _fbb,
      name__,
      frames__);
}

struct Frame FLATBUFFERS_FINAL_CLASS : private flatbuffers::Table {
  typedef FrameBuilder Builder;
  enum FlatBuffersVTableOffset FLATBUFFERS_VTABLE_UNDERLYING_TYPE {
    VT_LEFT = 4,
    VT_TOP = 6,
    VT_WIDTH = 8,
    VT_HEIGHT = 10
  };
  uint32_t left() const {
    return GetField<uint32_t>(VT_LEFT, 0);
  }
  uint32_t top() const {
    return GetField<uint32_t>(VT_TOP, 0);
  }
  uint32_t width() const {
    return GetField<uint32_t>(VT_WIDTH, 0);
  }
  uint32_t height() const {
    return GetField<uint32_t>(VT_HEIGHT, 0);
  }
  bool Verify(flatbuffers::Verifier &verifier) const {
    return VerifyTableStart(verifier) &&
           VerifyField<uint32_t>(verifier, VT_LEFT, 4) &&
           VerifyField<uint32_t>(verifier, VT_TOP, 4) &&
           VerifyField<uint32_t>(verifier, VT_WIDTH, 4) &&
           VerifyField<uint32_t>(verifier, VT_HEIGHT, 4) &&
           verifier.EndTable();
  }
};

struct FrameBuilder {
  typedef Frame Table;
  flatbuffers::FlatBufferBuilder &fbb_;
  flatbuffers::uoffset_t start_;
  void add_left(uint32_t left) {
    fbb_.AddElement<uint32_t>(Frame::VT_LEFT, left, 0);
  }
  void add_top(uint32_t top) {
    fbb_.AddElement<uint32_t>(Frame::VT_TOP, top, 0);
  }
  void add_width(uint32_t width) {
    fbb_.AddElement<uint32_t>(Frame::VT_WIDTH, width, 0);
  }
  void add_height(uint32_t height) {
    fbb_.AddElement<uint32_t>(Frame::VT_HEIGHT, height, 0);
  }
  explicit FrameBuilder(flatbuffers::FlatBufferBuilder &_fbb)
        : fbb_(_fbb) {
    start_ = fbb_.StartTable();
  }
  flatbuffers::Offset<Frame> Finish() {
    const auto end = fbb_.EndTable(start_);
    auto o = flatbuffers::Offset<Frame>(end);
    return o;
  }
};

inline flatbuffers::Offset<Frame> CreateFrame(
    flatbuffers::FlatBufferBuilder &_fbb,
    uint32_t left = 0,
    uint32_t top = 0,
    uint32_t width = 0,
    uint32_t height = 0) {
  FrameBuilder builder_(_fbb);
  builder_.add_height(height);
  builder_.add_width(width);
  builder_.add_top(top);
  builder_.add_left(left);
  return builder_.Finish();
}

inline const AnimationRoot *GetAnimationRoot(const void *buf) {
  return flatbuffers::GetRoot<AnimationRoot>(buf);
}

inline const AnimationRoot *GetSizePrefixedAnimationRoot(const void *buf) {
  return flatbuffers::GetSizePrefixedRoot<AnimationRoot>(buf);
}

inline bool VerifyAnimationRootBuffer(
    flatbuffers::Verifier &verifier) {
  return verifier.VerifyBuffer<AnimationRoot>(nullptr);
}

inline bool VerifySizePrefixedAnimationRootBuffer(
    flatbuffers::Verifier &verifier) {
  return verifier.VerifySizePrefixedBuffer<AnimationRoot>(nullptr);
}

inline void FinishAnimationRootBuffer(
    flatbuffers::FlatBufferBuilder &fbb,
    flatbuffers::Offset<AnimationRoot> root) {
  fbb.Finish(root);
}

inline void FinishSizePrefixedAnimationRootBuffer(
    flatbuffers::FlatBufferBuilder &fbb,
    flatbuffers::Offset<AnimationRoot> root) {
  fbb.FinishSizePrefixed(root);
}

#endif  // FLATBUFFERS_GENERATED_ANIMATIONS_H_
