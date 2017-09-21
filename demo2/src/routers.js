import Vue from 'vue'
import Router from 'vue-router'
Vue.use(Router)
import Index    from '@/pages/Index'
import ParentProps  from '@/pages/1-props/Parent.vue'
import ParentEmit  from '@/pages/2-emit/Parent.vue'
export default new Router({
  mode:"history",
  routes: [
    { path: '/',          name: 'Index',            component: Index         },
    { path: '/props',          name: 'ParentProps',      component: ParentProps   },
    { path: '/emit',          name: 'ParentEmit',      component: ParentEmit   },
  ]
})