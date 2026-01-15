<template>
  <Layout>
    <template #aside-outline-before>
      <div class="custom-outline-image">
        <img :src="currentImage" alt="UCAO-TECH Team" />
      </div>
    </template>
  </Layout>
</template>

<script setup>
import { computed } from 'vue'
import { useData, withBase } from 'vitepress'
import DefaultTheme from 'vitepress/theme'
const Layout = DefaultTheme.Layout
const { page } = useData()
const defaultImage = 'https://th.bing.com/th/id/OIP.P5l_4y7s4w-AIZXXxbMsxwHaEU?w=302&h=180&c=7&r=0&o=7&dpr=1.1&pid=1.7&rm=3'
const currentImage = computed(() => {
  const img = page.value.frontmatter?.outlineImage || defaultImage
  return img.startsWith('/') ? withBase(img) : img
})
</script>

<style>
.custom-outline-image {
  margin-top: 1rem;
  text-align: center;
}

.custom-outline-image img {
  max-width: 100%;
  height: auto;
  border-radius: 8px;
}
</style>