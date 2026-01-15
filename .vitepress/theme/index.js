import DefaultTheme from 'vitepress/theme'
import Layout from './Layout.vue'
import VideoPlayer from './VideoPlayer.vue'
import './custom.css'

export default {
  extends: DefaultTheme,
  Layout,
  enhanceApp({ app }) {
    app.component('VideoPlayer', VideoPlayer)
    if (typeof window !== 'undefined') {
      window.changeVideo = function(url) {
        const iframe = document.getElementById('video');
        if (iframe) iframe.src = url;
      }
    }
  }
}