include(FetchContent)

# gtest
FetchContent_Declare(
    googletest
    GIT_REPOSITORY https://gitee.com/mirrors/googletest.git
    GIT_TAG v1.14.0
    DOWNLOAD_EXTRACT_TIMESTAMP TRUE
)
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

# hiredis
FetchContent_Declare(
    hiredis
    GIT_REPOSITORY https://github.com/redis/hiredis.git
    GIT_TAG v1.2.0
    DOWNLOAD_EXTRACT_TIMESTAMP TRUE
)
FetchContent_MakeAvailable(hiredis)

# redis-plus-plus
FetchContent_Declare(
    redis-plus-plus
    GIT_REPOSITORY https://github.com/sewenew/redis-plus-plus.git
    GIT_TAG 1.3.12
    DOWNLOAD_EXTRACT_TIMESTAMP TRUE
)
FetchContent_MakeAvailable(redis-plus-plus)

# # 定义Boost的下载信息
# FetchContent_Declare(
# boost
# URL https://boostorg.jfrog.io/artifactory/main/release/1.85.0/source/boost_1_85_0.tar.gz
# )

# # 拉取Boost并使其可用
# FetchContent_MakeAvailable(Boost)
fetchcontent_declare(
    BoostAssert
    GIT_REPOSITORY https://github.com/boostorg/assert.git
    GIT_TAG boost-1.85.0)

fetchcontent_declare(
    BoostConfig
    GIT_REPOSITORY https://github.com/boostorg/config.git
    GIT_TAG boost-1.85.0)

fetchcontent_declare(
    BoostContainerHash
    GIT_REPOSITORY https://github.com/boostorg/container_hash.git
    GIT_TAG boost-1.85.0)

fetchcontent_declare(
    BoostCore
    GIT_REPOSITORY https://github.com/boostorg/core.git
    GIT_TAG boost-1.85.0)

fetchcontent_declare(
    BoostDetail
    GIT_REPOSITORY https://github.com/boostorg/detail.git
    GIT_TAG boost-1.85.0)

fetchcontent_declare(
    BoostStaticAssert
    GIT_REPOSITORY https://github.com/boostorg/static_assert.git
    GIT_TAG boost-1.85.0)

fetchcontent_declare(
    BoostThrowException
    GIT_REPOSITORY https://github.com/boostorg/throw_exception.git
    GIT_TAG boost-1.85.0)

fetchcontent_declare(
    BoostTypeTraits
    GIT_REPOSITORY https://github.com/boostorg/type_traits.git
    GIT_TAG boost-1.85.0)

fetchcontent_declare(
    BoostPreprocessor
    GIT_REPOSITORY https://github.com/boostorg/preprocessor.git
    GIT_TAG boost-1.85.0)

fetchcontent_declare(
    BoostIterator
    GIT_REPOSITORY https://github.com/boostorg/iterator.git
    GIT_TAG boost-1.85.0)

fetchcontent_declare(
    BoostIo
    GIT_REPOSITORY https://github.com/boostorg/io.git
    GIT_TAG boost-1.85.0)

fetchcontent_declare(
    BoostConceptCheck
    GIT_REPOSITORY https://github.com/boostorg/concept_check.git
    GIT_TAG boost-1.85.0)

fetchcontent_declare(
    BoostConversion
    GIT_REPOSITORY https://github.com/boostorg/conversion.git
    GIT_TAG boost-1.85.0)

fetchcontent_declare(
    BoostFunctionTypes
    GIT_REPOSITORY https://github.com/boostorg/function_types.git
    GIT_TAG boost-1.85.0)

fetchcontent_declare(
    BoostMpl
    GIT_REPOSITORY https://github.com/boostorg/mpl.git
    GIT_TAG boost-1.85.0)

fetchcontent_declare(
    BoostOptional
    GIT_REPOSITORY https://github.com/boostorg/optional.git
    GIT_TAG boost-1.85.0)

fetchcontent_declare(
    BoostSmartPtr
    GIT_REPOSITORY https://github.com/boostorg/smart_ptr.git
    GIT_TAG boost-1.85.0)

fetchcontent_declare(
    BoostUtility
    GIT_REPOSITORY https://github.com/boostorg/utility.git
    GIT_TAG boost-1.85.0)

fetchcontent_declare(
    BoostTypeof
    GIT_REPOSITORY https://github.com/boostorg/typeof.git
    GIT_TAG boost-1.85.0)

fetchcontent_declare(
    BoostTuple
    GIT_REPOSITORY https://github.com/boostorg/tuple.git
    GIT_TAG boost-1.85.0)

fetchcontent_declare(
    BoostPredef
    GIT_REPOSITORY https://github.com/boostorg/predef.git
    GIT_TAG boost-1.85.0)

fetchcontent_declare(
    BoostMove
    GIT_REPOSITORY https://github.com/boostorg/move.git
    GIT_TAG boost-1.85.0)

fetchcontent_declare(
    BoostAtomic
    GIT_REPOSITORY https://github.com/boostorg/atomic.git
    GIT_TAG boost-1.85.0)

fetchcontent_declare(
    BoostVariant2
    GIT_REPOSITORY https://github.com/boostorg/variant2.git
    GIT_TAG boost-1.85.0)

fetchcontent_declare(
    BoostAlign
    GIT_REPOSITORY https://github.com/boostorg/align.git
    GIT_TAG boost-1.85.0)

fetchcontent_declare(
    BoostMp11
    GIT_REPOSITORY https://github.com/boostorg/mp11.git
    GIT_TAG boost-1.85.0)
    
fetchcontent_declare(
    BoostWinapi
    GIT_REPOSITORY https://github.com/boostorg/winapi.git
    GIT_TAG boost-1.85.0)

fetchcontent_declare(
    BoostSystem
    GIT_REPOSITORY https://github.com/boostorg/system.git
    GIT_TAG boost-1.85.0)

fetchcontent_declare(
    BoostFileSystem
    GIT_REPOSITORY https://github.com/boostorg/filesystem.git
    GIT_TAG boost-1.85.0)

fetchcontent_declare(
    BoostDescribe
    GIT_REPOSITORY https://github.com/boostorg/describe.git
    GIT_TAG boost-1.85.0)

fetchcontent_declare(
    BoostFusion
    GIT_REPOSITORY https://github.com/boostorg/fusion.git
    GIT_TAG boost-1.85.0)

fetchcontent_declare(
    BoostFunctional
    GIT_REPOSITORY https://github.com/boostorg/functional.git
    GIT_TAG boost-1.85.0)

fetchcontent_declare(
    BoostFunction
    GIT_REPOSITORY https://github.com/boostorg/function.git
    GIT_TAG boost-1.85.0)

fetchcontent_declare(
    BoostBind
    GIT_REPOSITORY https://github.com/boostorg/bind.git
    GIT_TAG boost-1.85.0)

fetchcontent_declare(
    BoostScope
    GIT_REPOSITORY https://github.com/boostorg/scope.git
    GIT_TAG boost-1.85.0)

fetchcontent_makeavailable(
    BoostAssert
    BoostConfig
    BoostThrowException
    BoostVariant2
    BoostMp11
    BoostWinapi
    BoostPredef
    BoostContainerHash
    BoostDescribe
    BoostDetail
    BoostCore
    BoostPreprocessor
    BoostStaticAssert
    BoostTypeTraits
    BoostIo
    BoostIterator
    BoostConceptCheck
    BoostFunctionTypes
    BoostFusion
    BoostMpl
    BoostOptional
    BoostSmartPtr
    BoostUtility
    BoostTuple
    BoostTypeof
    BoostFunctional
    BoostMove
    BoostFunction
    BoostBind
    BoostScope
    BoostAtomic
    BoostAlign
    BoostSystem
    BoostFileSystem)