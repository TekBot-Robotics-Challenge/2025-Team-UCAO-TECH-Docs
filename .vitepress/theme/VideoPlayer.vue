<template>
  <div>
    <div class="button-container">
      <button v-for="i in 10" :key="i" class="video-button" :class="{ active: buttonTexts[i-1] == currentVideoNumber.toString() }" @click="handleClick(i-1)">{{ buttonTexts[i-1] }}</button>
    </div>
    <iframe id="video" width="560" height="315" :src="currentSrc" title="Vidéo d'assemblage du Rostmaster X3" frameborder="0" allow="accelerometer; autoplay; clipboard-write; encrypted-media; gyroscope; picture-in-picture; web-share" allowfullscreen></iframe>
  </div>
</template>

<script setup>
import { ref, onMounted } from 'vue'

const urls = [
  'https://www.youtube.com/embed/hi-zFwlzFAg',
  'https://www.youtube.com/embed/ANyQQb4RoKk',
  'https://www.youtube.com/embed/JpgTnUqsJwg',
  'https://www.youtube.com/embed/xeB1wAAyCWk',
  'https://www.youtube.com/embed/iDXbc_2_vas',
  'https://www.youtube.com/embed/W-CZaOUXWAU',
  'https://www.youtube.com/embed/7zHZReLWRyI',
  'https://www.youtube.com/embed/IhUYmvD4viQ',
  'https://www.youtube.com/embed/vOWtAXcirhM',
  'https://www.youtube.com/embed/0RZE4hyXaOM',
  'https://www.youtube.com/embed/dFoj-TB7mXo',
  'https://www.youtube.com/embed/yMSKUyDPlDI',
  'https://www.youtube.com/embed/QtPG3repigc',
  'https://www.youtube.com/embed/P851g4oVrTA',
  'https://www.youtube.com/embed/2kgiIsndghw',
  'https://www.youtube.com/embed/BdN_ZpZTpNo',
  'https://www.youtube.com/embed/QtPG3repigc?list=PL6KtTPU_PfxrRSeDjxQsKbpgoGmKgRIy3',
  'https://www.youtube.com/embed/7dNwJV0QkUE'
]
let currentStart = ref(1)
const currentSrc = ref('https://www.youtube.com/embed/hi-zFwlzFAg?list=PL7cl5vr6XctRdJozdq-OijNkPeM5M0uZ7&mute=1')
const currentVideoNumber = ref(1)
const buttonTexts = ref(Array(10).fill(''))

const updateButtons = () => {
  const buttons = buttonTexts.value
  // First button
  if (currentStart.value > 1) {
    buttons[0] = '<'
  } else {
    buttons[0] = '1'
  }
  // Videos
  if (currentStart.value === 1) {
    for (let j = 1; j <= 8; j++) {
      buttons[j] = (currentStart.value + j).toString()
    }
  } else {
    for (let j = 1; j <= 9; j++) {
      buttons[j] = (currentStart.value + j - 1).toString()
    }
  }
  // Last button
  if (currentStart.value + 9 <= 18) {
    buttons[9] = '>'
  }
}

const handleClick = (index) => {
  const text = buttonTexts.value[index]
  if (text === '<') {
    currentStart.value -= 9
    updateButtons()
  } else if (text === '>') {
    currentStart.value += 9
    updateButtons()
  } else {
    let num = parseInt(text)
    if (num >= 1 && num <= 18) {
      currentSrc.value = urls[num - 1] + '?mute=1'
      currentVideoNumber.value = num
    }
  }
}

onMounted(() => {
  updateButtons()
})
</script>

<style scoped>
.button-container {
  display: flex;
  width: 560px;
  background: var(--vp-c-bg-soft);
  padding: 5px;
  border: 1px solid var(--vp-c-border);
}

.video-button {
  width: 56px;
  height: 30px;
  border: 1px solid var(--vp-c-border);
  background: var(--vp-c-bg);
  color: var(--vp-c-text-1);
  cursor: pointer;
}

.active {
  background: var(--vp-c-brand) !important;
  color: var(--vp-c-bg) !important;
}
</style>