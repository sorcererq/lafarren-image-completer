//
// Copyright 2010, Darren Lafreniere
// <http://www.lafarren.com/image-completer/>
//
// This file is part of lafarren.com's Image Completer.
//
// Image Completer is free software: you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.
//
// Image Completer is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.
//
// You should have received a copy of the GNU General Public License
// along with Image Completer, named License.txt. If not, see
// <http://www.gnu.org/licenses/>.
//

#ifndef PATCH_IMAGE_SOURCE_ORDER_H
#define PATCH_IMAGE_SOURCE_ORDER_H

#include "CompositorRoot.h"
#include "ImageFloat.h"

namespace LfnIc
{
	struct Settings;

	///
	/// Serves color-coded patches based on their prioritized order:
	/// red patches are applied to the output first, violet patches are applied
	/// last, and patches in the middle take the middle colors of the spectrum.
	///
	class PatchTypeDebugPatchOrder : public CompositorRoot::PatchType
	{
	public:
		struct Factory : public CompositorRoot::PatchType::Factory
		{
			virtual CompositorRoot::PatchType* Create(const Compositor::Input& input, ImageFloat& imageFloat) const;
		};

		PatchTypeDebugPatchOrder(const Compositor::Input& input, ImageFloat& imageFloat);
		virtual const ImageFloat& Get(const Patch& patch) const;

	private:
		const std::vector<Patch>& m_patches;
		mutable ImageFloat m_patchImage;
	};
}

#endif // PATCH_IMAGE_SOURCE_ORDER_H
