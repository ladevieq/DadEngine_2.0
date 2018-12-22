#ifndef __VULKAN_RENDER_CONTEXT_HPP_
#define __VULKAN_RENDER_CONTEXT_HPP_

#include <vulkan/vulkan.hpp>

#include "../../../core/core.hpp"
#include "../render-context.hpp"

#include "vulkan-depth-stencil-buffer.hpp"
#include "vulkan-renderpass.hpp"

namespace DadEngine::Rendering
{
    class VulkanSwapchain;
    class VulkanImage;
	class VulkanFramebuffer;

	class VulkanRenderContext : public RenderContext
	{

	public:

		VulkanRenderContext(PlatformWindow& _InWindow);
		~VulkanRenderContext();

		void ClearColorBuffer(Color& _InClearColor, CommandBuffer* _InCommandBuffer) override final;

		void ClearDepthStencilBuffer(float _InDepthValue,
                                     uint32_t _InStencilValue,
                                     CommandBuffer *_InCommandBuffer) override final;

		void Present(CommandBuffer* _InCommandBuffer) override final;

		void Draw(VertexBuffer* _InVertexBuffer, CommandBuffer* _InCommandBuffer) override final;

		void DrawMultiples(VertexBuffer* _InVertexBuffer, int32_t _InInstanceCount, CommandBuffer* _InCommandBuffer) override final;

		void BindVertexBuffer(VertexBuffer* _InVertexBuffer, CommandBuffer* _InCommandBuffer) override final;

		void BindShaderProgram(Shader* _InShader, CommandBuffer* _InCommandBuffer) override final;

		void BeginRenderPass(RenderPass* _InRenderPass, Framebuffer* _InFrameBuffer, CommandBuffer* _InCommandBuffer) override final;

		void EndRenderPass(CommandBuffer* _InCommandBuffer) override final;


		void SetViewport(Viewport& _InViewport, CommandBuffer* _InCommandBuffer) override final;

		void SetCullingMode(CullingMode _InCullingMode, CommandBuffer* _InCommandBuffer) override final;

		void SetFillMode(FillMode _InFillMode, CommandBuffer* _InCommandBuffer) override final;


		Image* GetBackBuffer() override final;

		Image* GetDepthStencilBuffer() override final;

		Framebuffer* GetBackFramebuffer() override final;

		RenderPass* GetRenderPass() override final;


		void BeginFrame() override final;

		void EndFrame() override final;

		void SubmitCommandBuffer(CommandBuffer* _InCommandBuffer) override final;


		VertexBuffer *CreateVertexBuffer(uint32_t _InVertexCount,
                                         TArray<float> &_InData,
                                         TArray<VertexInput> &_InVertexLayout,
                                         uint32_t _InVerticesStride) override final;
		VertexShader* CreateVertexShader(const char* _InShaderCode, size_t _InShaderCodeSize, TArray<VertexInput>& _InVertexInputLayout) override final;
		GeometryShader* CreateGeometryShader(const char* _InShaderCode, size_t _InShaderCodeSize) override final;
		FragmentShader* CreateFragmentShader(const char* _InShaderCode, size_t _InShaderCodeSize) override final;
		Shader* CreateShader(VertexShader* _InVertexShader, GeometryShader* _InGeometryShader, FragmentShader* _InFragmentShader, RenderPass* _InRenderpass) override final;
		CommandBuffer* CreateCommandBuffer() override final;
		RenderPass* CreateRenderPass(TArray<Image*>& _InImage) override final;
		Framebuffer* CreateFramebuffer(Extent2D& _InFramebufferSize, RenderPass* _InRenderPass) override final;


	private:

		void CreateInstance(PlatformWindow& _InWindow);

		void CreateDevice();

		void CreateCommandPool();

		void CreateDescriptorPool();

		void CreateSetupCommandBuffer();

		void GetQueues(); // Present and Graphics

		void GetPresentationMode(PlatformWindow& _InWindow);

		void DestroySetupCommandBuffer();

		void CreatePresentationSurface(PlatformWindow& _InWindow);

		void CreateDepthStencilBuffer();

		void CreateRenderpass();

		void CreateSemaphores();

		void CreateFences();

		void CreatePipelineCache();

		void CreateFramebuffers();


		uint32_t m_uiGraphicsQueueFamilyIndex = 0U;
        uint32_t m_uiPresentationsQueueFamilyIndex = 0U;

		VkInstance m_Instance = VK_NULL_HANDLE;
		VkDevice m_Device = VK_NULL_HANDLE; // Logical device
		VkPhysicalDevice m_PhysicalDevice = VK_NULL_HANDLE;
		VkPhysicalDeviceMemoryProperties m_PhysicalDeviceMemoryProperties;

		VkQueue m_GraphicsQueue = VK_NULL_HANDLE;
		VkQueue m_PresentationQueue = VK_NULL_HANDLE;

		VkSemaphore m_ImageAvailableSemaphore = VK_NULL_HANDLE;
		VkSemaphore m_RenderingFinishedSemaphore = VK_NULL_HANDLE;

		TArray<VkFence> m_CommandBufferAvailables;

		VkCommandPool m_GraphicsCommandPool = VK_NULL_HANDLE;
		VkCommandPool m_PresentationCommandPool = VK_NULL_HANDLE;

		VkDescriptorPool m_UBODescriptorPool = VK_NULL_HANDLE;

		VkCommandBuffer m_SetupCommandBuffer = VK_NULL_HANDLE;
		//TArray<VulkanCommandBuffer> m_FinalCommandBuffers;

		TArray<VkCommandBuffer> m_SubmittedCommandBuffers;

		VulkanSwapchain* m_Swapchain = nullptr;

		VkSurfaceKHR m_PresentationSurface = VK_NULL_HANDLE;

		VkExtent2D m_WindowExtent;

		VulkanImage* m_BackBuffer = nullptr;
		VulkanDepthStencilBuffer m_DepthStencilBuffer;

		VulkanRenderPass m_Renderpass;
		//VkRenderPass m_Renderpass = VK_NULL_HANDLE;
		//TArray<VkRenderPass> m_Renderpasses;

		VkPipelineCache m_PipelineCache = VK_NULL_HANDLE;

		VkPresentModeKHR m_PresentationMode;

		TArray<VulkanFramebuffer> m_Framebuffers;

		uint32_t m_uiNextImage = 0U;
	};
}

#endif //__VULKAN_RENDER_CONTEXT_HPP_