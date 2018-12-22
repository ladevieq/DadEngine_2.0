#ifndef __FRAMEBUFFER_HPP_
#define __FRAMEBUFFER_HPP_

namespace DadEngine::Rendering
{
	enum AttachmentPoints
	{
		FRAMEBUFFER_COLOR_ATTACHMENT,
		FRAMEBUFFER_DEPTH_ATTACHMENT,
		FRAMEBUFFER_STENCIL_ATTACHMENT,
		FRAMEBUFFER_DEPTH_STENCIL_ATTACHMENT,
		MAX_FRAMEBUFFER_ATTACHMENT
	};

	struct FramebufferAttachement
	{
		AttachmentPoints m_AttachmentPoint = MAX_FRAMEBUFFER_ATTACHMENT;
	};

	class Framebuffer
	{

	public:

	};
}

#endif //__FRAMEBUFFER_HPP_