/* SourceMap-Qt
 * (C) Copyright 2014 HicknHack Software GmbH
 *
 * The original code can be found at:
 *     https://github.com/hicknhack-software/SourceMap-Qt
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */
#ifndef SOURCEMAP_META_CONCAT_TUPLES_H
#define SOURCEMAP_META_CONCAT_TUPLES_H

#include <tuple>

namespace SourceMap {
namespace meta {

template< typename... >
struct concat_tuples;

template<>
struct concat_tuples<>
{
    using type = std::tuple<>;
};

template< typename... Types >
struct concat_tuples< std::tuple<Types...> >
{
    using type = std::tuple<Types...>;
};

template< typename... Types, typename... More, typename... Tail >
struct concat_tuples< std::tuple<Types...>, std::tuple<More...>, Tail... >
{
    using type = typename concat_tuples< std::tuple<Types..., More...>, Tail... >::type;
};

template< typename... Types >
using concat_tuples_t = typename concat_tuples< Types... >::type;

} // namespace meta
} // namespace SourceMap

#endif // SOURCEMAP_META_CONCAT_TUPLES_H