<template>
  <div class="parent">
   <h1>父组件（灰色背景）</h1>
    <input type="text" v-model="msg" >
    <Child :message="msg"></Child>
  </div>
</template>
<script>
  import Child from "./Child.vue";
  export default {
    data(){
      return {
        msg : "改变会发送给子组件"
      }
    },
    components: {Child}
  }
</script>
<style>
  .parent{
    background-color: gainsboro;
    height: 400px;
  }
  .parent input{
    width: 300px;
    height: 35px;
    line-height: 35px;
    font-size: 18px;
  }
</style>
