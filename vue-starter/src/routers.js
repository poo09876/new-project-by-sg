import Vue from 'vue'
import Router from 'vue-router'
Vue.use(Router)
import Index    from '@/pages/Index'
import ParentProps  from '@/pages/1-props/Parent.vue'
import ParentEmit   from '@/pages/2-emit/Parent.vue'
import Parent2Way   from '@/pages/3-2way/Parent.vue'
import BusDemo      from '@/pages/4-bus/Demo.vue'
import TodoDemo     from '@/pages/5-todo/index.vue'
import TodoVuex     from '@/pages/6-todo-vuex/index.vue'
export default new Router({
  mode:"history",
  routes: [
    { path: '/',          name: 'Index',          component: Index        },
    { path: '/props',     name: 'ParentProps',    component: ParentProps  },
    { path: '/emit',      name: 'ParentEmit',     component: ParentEmit   },
    { path: '/2way',      name: 'Parent2Way',     component: Parent2Way   },
    { path: '/bus',       name: 'BusDemo',        component: BusDemo      },
    { path: '/todo',      name: 'TodoDemo',       component: TodoDemo     },
    { path: '/todo-vuex',      name: 'TodoVuex',       component: TodoVuex     },
  ]
})