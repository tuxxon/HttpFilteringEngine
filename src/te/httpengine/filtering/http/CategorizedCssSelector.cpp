/*
* Copyright (c) 2016 Jesse Nicholson.
*
* This file is part of Http Filtering Engine.
*
* Http Filtering Engine is free software: you can redistribute it and/or
* modify it under the terms of the GNU General Public License as published
* by the Free Software Foundation, either version 3 of the License, or (at
* your option) any later version.
*
* In addition, as a special exception, the copyright holders give
* permission to link the code of portions of this program with the OpenSSL
* library.
*
* You must obey the GNU General Public License in all respects for all of
* the code used other than OpenSSL. If you modify file(s) with this
* exception, you may extend this exception to your version of the file(s),
* but you are not obligated to do so. If you do not wish to do so, delete
* this exception statement from your version. If you delete this exception
* statement from all source files in the program, then also delete it
* here.
*
* Http Filtering Engine is distributed in the hope that it will be useful,
* but WITHOUT ANY WARRANTY; without even the implied warranty of
* MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General
* Public License for more details.
*
* You should have received a copy of the GNU General Public License along
* with Http Filtering Engine. If not, see <http://www.gnu.org/licenses/>.
*/

#include "CategorizedCssSelector.hpp"
#include <Parser.hpp>
namespace te
{
	namespace httpengine
	{
		namespace filtering
		{
			namespace http
			{

				CategorizedCssSelector::CategorizedCssSelector(boost::string_ref domains, std::string selectorString, const uint8_t category)
					:m_domains(domains), m_category(category)
				{
					gq::Parser parser;

					// This can throw std::runtime_error!
					m_compiledSelector = parser.CreateSelector(selectorString, true);
				}

				CategorizedCssSelector::~CategorizedCssSelector()
				{

				}

				const boost::string_ref CategorizedCssSelector::GetOriginalSelectorString() const
				{
					if (m_compiledSelector != nullptr)
					{
						return m_compiledSelector->GetOriginalSelectorString();
					}

					return boost::string_ref();
				}

				const uint8_t CategorizedCssSelector::GetCategory() const
				{
					return m_category;
				}

				const gq::SharedSelector& CategorizedCssSelector::GetSelector() const
				{
					return m_compiledSelector;
				}

				const boost::string_ref CategorizedCssSelector::GetDomains() const
				{
					return m_domains;
				}

			} /* namespace http */
		} /* namespace filtering */
	} /* namespace httpengine */
} /* namespace te */