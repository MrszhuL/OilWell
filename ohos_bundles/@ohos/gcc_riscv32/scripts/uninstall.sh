HPM_FILE_NAME="gcc_riscv32.tar"

# HPM_GCC_INSTALL 用户可在hpmrc中配置的 gcc安装地址 调用 卸载都依赖于该值

if [ ! ${HPM_GCC_INSTALL} ]; then
    HPM_GCC_INSTALL=${globalRepo}
fi

rm -rf ${HPM_GCC_INSTALL}/gcc_riscv32

rm  ${HPM_FILE_NAME}
